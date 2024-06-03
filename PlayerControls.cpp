#include "PlayerControls.h"

PlayerControls::PlayerControls(QObject *parent) : QObject(parent) {}

void PlayerControls::Play() {
    emit PlayRequested();
}

void PlayerControls::Pause() {
    emit PauseRequested();
}

void PlayerControls::Next() {
    emit NextRequested();
}

void PlayerControls::Previous() {
    emit PreviousRequested();
}