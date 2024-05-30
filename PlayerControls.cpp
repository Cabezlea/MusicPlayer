#include "PlayerControls.h"

PlayerControls::PlayerControls(QObject *parent) : QObject(parent) {}

void PlayerControls::Play()
{
    emit PlayRequested();
}

void PlayerControls::Pause()
{
    // Implement Pause logic here
}

void PlayerControls::Next()
{
    // Implement Next logic here
}

void PlayerControls::Previous()
{
    // Implement Previous logic here
}
