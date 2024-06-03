//
// Created by User on 5/6/24.
//

#ifndef UNTITLED_PLAYERCONTROLS_H
#define UNTITLED_PLAYERCONTROLS_H

#include<QWidget>

class PlayerControls : public QObject {
Q_OBJECT

public:
    PlayerControls(QObject *parent = nullptr);
    void Play();
    void Pause();
    void Next();
    void Previous();

signals:
    void PlayRequested();
    void PauseRequested();
    void NextRequested();
    void PreviousRequested();
};


#endif //UNTITLED_PLAYERCONTROLS_H