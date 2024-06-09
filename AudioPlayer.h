#ifndef UNTITLED_AUDIOPLAYER_H
#define UNTITLED_AUDIOPLAYER_H

#include <QObject>
#include "portaudio.h"
#include "sndfile.h"
#include "mpg123.h"
#include <string>
#include <vector>
#include <QTimer>

class AudioPlayer : public QObject {
Q_OBJECT

public:
    explicit AudioPlayer(QObject *parent = nullptr);
    ~AudioPlayer();
    void updateElapsedTime();
    void setVolume(int volume);
    void LoadSongsFromDirectory(const std::string &directoryPath);
    void OpenFiles(const std::string &filePath);
    void PlaySound();
    void PauseSound();
    void ResumeSound();
    void StopSound();
    void PlayNextSong();
    void RewindSong();
    void ManageBuffer();
    QString getCurrentSongPath() const;  // To get the path of the current playing song
    int elapsedTimeInSeconds;
    int totalDurationInSeconds;

private:
    QTimer *timer;
    float volumeLevel;
    PaStream *stream;
    SNDFILE *sndFile;
    SF_INFO sfInfo;
    mpg123_handle *m_mpg123_handle;  // MPG123 handle for MP3 decoding
    float *buffer;
    std::vector<std::string> songList;
    int currentSongIndex;
    bool isPlaying;
    static const size_t bufferSize = 4096;  // Define a suitable buffer size

    static int audioCallback(const void *input, void *output, unsigned long frameCount,
                             const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags,
                             void *userData);

signals:
    void PlaybackFinished();
    void songChanged();
    void timeUpdated(int elapsedTime, int remainingTime);
};
#endif // UNTITLED_AUDIOPLAYER_H
