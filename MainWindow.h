//In this h class we declare the class and its functions
//We also declare the private fields and the public stuff
//We do private: declaration and public:declaration

#ifndef UNTITLED_MAINWINDOW_H
#define UNTITLED_MAINWINDOW_H

#include <QWidget>
#include "AudioPlayer.h"
#include "PlayerControls.h"
#include <QPixmap>

class MainWindow : public QWidget {

Q_OBJECT
private:
    //Private fields
    PlayerControls *playerControls;
    AudioPlayer *audioPlayer;

protected:
    void paintEvent(QPaintEvent *event) override;

public:
    QPixmap songImage;
    MainWindow(); //Constructor for the class
    void Menus(); // methods for the class
    void Toolbars();
    void StatusBar();
    void loadSongs(const QString &directoryPath);
    void loadAlbumArt();
    QImage extractAlbumArt(const QString& filePath);
};


#endif //UNTITLED_MAINWINDOW_H