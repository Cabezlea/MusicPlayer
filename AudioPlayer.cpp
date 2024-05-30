#include "AudioPlayer.h"
#include "portaudio.h"
#include "sndfile.h"
#include <iostream>
#include <filesystem>

AudioPlayer::AudioPlayer(QObject *parent) : QObject(parent), stream(nullptr), sndFile(nullptr), buffer(nullptr), currentSongIndex(0) {
    // Initialize PortAudio
    PaError err = Pa_Initialize();
    if (err != paNoError) {
        std::cerr << "PortAudio error: " << Pa_GetErrorText(err) << std::endl;
    }

    // Load songs from a specified directory
    LoadSongsFromDirectory("/Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/Songs");  // Replace with your actual path
}

AudioPlayer::~AudioPlayer() {
    Pa_Terminate();
    delete[] buffer;
}

void AudioPlayer::LoadSongsFromDirectory(const std::string &directoryPath) {
    std::cout << "Loading songs from directory: " << directoryPath << std::endl;
    for (const auto &entry : std::filesystem::directory_iterator(directoryPath)) {
        std::cout << "Found file: " << entry.path() << " with extension: " << entry.path().extension() << std::endl;
        if (entry.path().extension() == ".m4a" || entry.path().extension() == ".wav") {
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
    outputParameters.channelCount = sfInfo.channels;  // stereo output
    outputParameters.sampleFormat = paFloat32;
    outputParameters.suggestedLatency = Pa_GetDeviceInfo(outputParameters.device)->defaultLowOutputLatency;
    outputParameters.hostApiSpecificStreamInfo = NULL;

    PaError err = Pa_OpenStream(
            &stream,
            NULL, // no input
            &outputParameters,
            sfInfo.samplerate, // sample rate
            paFramesPerBufferUnspecified,
            paClipOff, // no clipping
            audioCallback, // callback function
            this // user data
    );

    if (err != paNoError) {
        std::cerr << "PortAudio error: " << Pa_GetErrorText(err) << std::endl;
    }

    err = Pa_StartStream(stream);
    if (err != paNoError) {
        std::cerr << "PortAudio error: " << Pa_GetErrorText(err) << std::endl;
    }
}

void AudioPlayer::StopSound() {
    PaError err = Pa_StopStream(stream);
    if (err != paNoError) {
        std::cerr << "PortAudio error: " << Pa_GetErrorText(err) << std::endl;
    }

    Pa_CloseStream(stream);
    sf_close(sndFile);

    delete[] buffer; // Clean up the buffer
    buffer = nullptr;
    sndFile = nullptr;
    stream = nullptr;
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
        *out++ = player->buffer[i];
    }
    return paContinue;
}

void AudioPlayer::PlayNextSong() {
    currentSongIndex++;
    PlaySound();
}
