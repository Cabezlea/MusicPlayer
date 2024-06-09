//In this h class we declare the class and its functions
//We also declare the private fields and the public stuff
//We do private: declaration and public:declaration

#ifndef UNTITLED_MAINWINDOW_H
#define UNTITLED_MAINWINDOW_H

#include <QWidget>
#include "AudioPlayer.h"
#include "PlayerControls.h"
#include <QPixmap>
#include <QProcess>
#include <QLabel>

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
    QLabel *songTitleLabel;
    QLabel *artistLabel;
    QString currentSongTitle;
    QString currentArtist;
    MainWindow(); //Constructor for the class
    void Menus(); // methods for the class
    void Toolbars();
    void StatusBar();
    void loadSongs(const QString &directoryPath);
    void loadAlbumArt();
    void loadMetadata();
};


#endif //UNTITLED_MAINWINDOW_H
