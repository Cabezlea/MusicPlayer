#include "AudioPlayer.h"
#include "portaudio.h"
#include "sndfile.h"
#include <iostream>


AudioPlayer::AudioPlayer(QObject *parent) : QObject(parent)
{
    // Initialize PortAudio here
    PaError err = Pa_Initialize();
            if(err != paNoError){
                std::cerr << "PortAudio error" << Pa_GetErrorText(err) << std:: endl;
            }
}

void AudioPlayer::PlaySound()
{
    PaStreamParameters outputParameters;
    outputParameters.device = Pa_GetDefaultOutputDevice();
    outputParameters.channelCount = 2;       // stereo output
    outputParameters.sampleFormat = paFloat32;
    outputParameters.suggestedLatency = Pa_GetDeviceInfo(outputParameters.device)->defaultLowOutputLatency;
    outputParameters.hostApiSpecificStreamInfo = NULL;

    PaError err = Pa_OpenStream(
            &stream,
            NULL, // no input
            &outputParameters,
            44100, // sample rate
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

void AudioPlayer::OpenFiles()
{
    // Implement file opening logic here
}

void AudioPlayer::ManageBuffer()
{
    // Implement buffer management logic here
}

void AudioPlayer::PlayBack()
{
    // Implement playback control logic here
}

int AudioPlayer::audioCallback(const void *input, void *output, unsigned long frameCount,
                         const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags,
                         void *userData)
{
    AudioPlayer *player = static_cast<AudioPlayer *>(userData);
    float *out = (float *)output;
    // Fill the output buffer with audio data
    for (unsigned long i = 0; i < frameCount; i++) {
        *out++ = 0.0f; // Left channel
        *out++ = 0.0f; // Right channel
    }
    return paContinue;
}
