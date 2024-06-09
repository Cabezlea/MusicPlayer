#include "AudioPlayer.h"
#include "portaudio.h"
#include "sndfile.h"
#include "mpg123.h"
#include <iostream>
#include <filesystem>
#include <QTimer>

AudioPlayer::AudioPlayer(QObject *parent)
        : QObject(parent), stream(nullptr), sndFile(nullptr), m_mpg123_handle(nullptr), buffer(nullptr),
          currentSongIndex(0), isPlaying(false), volumeLevel(1.0) {
    // Initialize PortAudio
    PaError err = Pa_Initialize();
    if (err != paNoError) {
        std::cerr << "PortAudio error: " << Pa_GetErrorText(err) << std::endl;
    }

    // Initialize mpg123 for MP3 support
    mpg123_init();
    m_mpg123_handle = mpg123_new(NULL, NULL);

    // Load songs from the specified directory
    LoadSongsFromDirectory("/Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/Songs");
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &AudioPlayer::updateElapsedTime);
}

AudioPlayer::~AudioPlayer() {
    if (stream) {
        Pa_StopStream(stream);
        Pa_CloseStream(stream);
    }
    if (m_mpg123_handle) {
        mpg123_close(m_mpg123_handle);
        mpg123_delete(m_mpg123_handle);
        mpg123_exit();
    }
    Pa_Terminate();
    delete[] buffer;
}


void AudioPlayer::LoadSongsFromDirectory(const std::string &directoryPath) {
    std::cout << "Loading songs from directory: " << directoryPath << std::endl;
    for (const auto &entry : std::filesystem::directory_iterator(directoryPath)) {
        if (entry.path().extension() == ".m4a" || entry.path().extension() == ".wav" || entry.path().extension() == ".mp3") {
            songList.push_back(entry.path().string());
            std::cout << "Loaded: " << entry.path().string() << std::endl;
        }
    }
    if (songList.empty()) {
        std::cout << "No songs loaded." << std::endl;
    }
}

void AudioPlayer::OpenFiles(const std::string &filePath) {
    sfInfo.format = 0;
    sndFile = sf_open(filePath.c_str(), SFM_READ, &sfInfo);
    if (!sndFile) {
        std::cerr << "Error opening audio file: " << sf_strerror(sndFile) << std::endl;
        return;
    }
    buffer = new float[bufferSize * sfInfo.channels];
}

void AudioPlayer::PlaySound() {
    if (songList.empty()) {
        std::cerr << "No songs loaded." << std::endl;
        return;
    }

    if (currentSongIndex >= songList.size()) {
        currentSongIndex = 0; // Restart playlist
    }

    OpenFiles(songList[currentSongIndex]);

    PaStreamParameters outputParameters;
    outputParameters.device = Pa_GetDefaultOutputDevice();
    outputParameters.channelCount = sfInfo.channels;
    outputParameters.sampleFormat = paFloat32;
    outputParameters.suggestedLatency = Pa_GetDeviceInfo(outputParameters.device)->defaultLowOutputLatency;
    outputParameters.hostApiSpecificStreamInfo = NULL;

    PaError err = Pa_OpenStream(&stream, NULL, &outputParameters, sfInfo.samplerate, paFramesPerBufferUnspecified, paClipOff, audioCallback, this);
    if (err != paNoError) {
        std::cerr << "PortAudio error: " << Pa_GetErrorText(err) << std::endl;
        return;
    }

    err = Pa_StartStream(stream);
    if (err != paNoError) {
        std::cerr << "PortAudio error: " << Pa_GetErrorText(err) << std::endl;
        return;
    }
    isPlaying = true;
    totalDurationInSeconds = sfInfo.frames / sfInfo.samplerate;
    elapsedTimeInSeconds = 0;
    timer->start(1000); // Update every second
}

void AudioPlayer::updateElapsedTime() {
    if (isPlaying) {
        elapsedTimeInSeconds++;
        emit timeUpdated(elapsedTimeInSeconds, totalDurationInSeconds - elapsedTimeInSeconds);
    }
}

void AudioPlayer::PauseSound() {
    if (isPlaying && stream) {
        PaError err = Pa_StopStream(stream);
        if (err != paNoError) {
            std::cerr << "PortAudio error: " << Pa_GetErrorText(err) << std::endl;
        } else {
            isPlaying = false;
        }
    }
    timer->stop();
}

void AudioPlayer::ResumeSound() {
    if (!isPlaying && stream) {
        PaError err = Pa_StartStream(stream);
        if (err != paNoError) {
            std::cerr << "PortAudio error: " << Pa_GetErrorText(err) << std::endl;
        } else {
            isPlaying = true;
        }
    }
    timer->stop();
}

void AudioPlayer::StopSound() {
    if (stream) {
        PaError err = Pa_StopStream(stream);
        if (err != paNoError) {
            std::cerr << "PortAudio error: " << Pa_GetErrorText(err) << std::endl;
        }
        Pa_CloseStream(stream);
        sf_close(sndFile);

        delete[] buffer;
        buffer = nullptr;
        sndFile = nullptr;
        stream = nullptr;
        isPlaying = false;
    }
    timer->stop();
    elapsedTimeInSeconds = 0;
}

void AudioPlayer::ManageBuffer() {
    // Read audio data into buffer
    sf_count_t numFrames = sf_readf_float(sndFile, buffer, bufferSize);
    if (numFrames < bufferSize) {
        // Handle end of file or read error
        emit PlaybackFinished();
    }
}

int AudioPlayer::audioCallback(const void *input, void *output, unsigned long frameCount,
                               const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags,
                               void *userData) {
    AudioPlayer *player = static_cast<AudioPlayer *>(userData);
    float *out = (float *)output;

    sf_count_t numRead = sf_readf_float(player->sndFile, player->buffer, frameCount);
    if (numRead < frameCount) {
        // Handle end of file or read error
        player->StopSound();
        player->PlayNextSong();
        return paComplete;
    }

    for (unsigned long i = 0; i < frameCount * player->sfInfo.channels; i++) {
        *out++ = player->buffer[i] * player->volumeLevel;
    }
    return paContinue;
}

void AudioPlayer::PlayNextSong() {
    currentSongIndex++;
    PlaySound();
    emit songChanged();
}

void AudioPlayer::RewindSong() {

    //Check if we are at the first song, if so we wrap around to the last song
    if (currentSongIndex == 0){
        currentSongIndex = songList.size() - 1; //If first song, it moves to the last song
    }
    else {
        currentSongIndex--; //Else we decrement and go back to the previous song
    }

    PlaySound(); //Implementation of the PlaySound method
}

QString AudioPlayer::getCurrentSongPath() const {
    if (currentSongIndex < songList.size())
        return QString::fromStdString(songList[currentSongIndex]);
    return QString();
}
void AudioPlayer::setVolume(int volume) {
    volumeLevel = volume / 100.0f; //Convert volume from 0-100 scale to float 0.0 - 1.0
}

