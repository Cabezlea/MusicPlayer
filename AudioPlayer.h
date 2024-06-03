#ifndef UNTITLED_AUDIOPLAYER_H
#define UNTITLED_AUDIOPLAYER_H

#include <QObject>
#include "portaudio.h"
#include "sndfile.h"
#include <string>
#include <vector>

class AudioPlayer : public QObject {
Q_OBJECT

public:
    AudioPlayer(QObject *parent = nullptr);
    ~AudioPlayer();
    void OpenFiles(const std::string &filePath);
    void PlaySound();
    void StopSound();
    void PauseSound();
    void ResumeSound();
    void ManageBuffer();
    void LoadSongsFromDirectory(const std::string &directoryPath);
    void PlayNextSong();

private:
    PaStream *stream;
    SNDFILE *sndFile;
    SF_INFO sfInfo;
    float *buffer;
    std::vector<std::string> songList;
    int currentSongIndex;
    bool isPlaying;
    static int audioCallback(const void *input, void *output, unsigned long frameCount,
                             const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags,
                             void *userData);
    size_t bufferSize = 1024;

signals:
    void PlaybackFinished();
};

#endif // UNTITLED_AUDIOPLAYER_H