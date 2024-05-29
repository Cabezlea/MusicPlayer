//
// Created by User on 5/6/24.
//

#ifndef UNTITLED_AUDIOPLAYER_H
#define UNTITLED_AUDIOPLAYER_H


#include <QObject>

class AudioPlayer : public QObject
{
Q_OBJECT
public:
    AudioPlayer(QObject *parent = nullptr);
    void PlaySound();
    void OpenFiles();
    void ManageBuffer();
    void PlayBack();
};



#endif //UNTITLED_AUDIOPLAYER_H
