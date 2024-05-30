//
// Created by User on 5/6/24.
//

#ifndef UNTITLED_AUDIOPLAYER_H
#define UNTITLED_AUDIOPLAYER_H


#include <QObject>
#include "portaudio.h"
#include "sndfile.h"

class AudioPlayer : public QObject
{
Q_OBJECT

private:
    PaStream *stream;
static int audioCallback(const void *input, void *output, unsigned long frameCount,
                         const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags,
                         void *userData);
public:
    AudioPlayer(QObject *parent = nullptr);
    void PlaySound();
    void OpenFiles();
    void ManageBuffer();
    void PlayBack();
};



#endif //UNTITLED_AUDIOPLAYER_H
