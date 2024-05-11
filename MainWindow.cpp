//This is where we define the class functions do
#include "MainWindow.h"
#include <QMenuBar>
#include <QLabel>
#include <QWidget>
#include <Qpainter>


MainWindow::MainWindow() {
    Menus();
    Toolbars();
    StatusBar();

    QString title = "Open Source Music Player in C++";
    setWindowTitle(title);

    resize(800,600); //Screen size
    // Load the background image using the absolute file path
    //QPixmap is a class provided by QT to handle images in applications, we create an object named bkgnd
    QPixmap bkgnd("/Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/Images/Tron.png"); // Replace "/home/user/Pictures/background.png" with the actual path to your image file

    if (!bkgnd.isNull()) { // Check if the pixmap is valid
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio); //If valid scales image to window size

        // Create a palette and set the background image
        QPalette palette;
        palette.setBrush(QPalette::Window, bkgnd); //setBrush method used to set background, QPalette::Window represents the window area of palette
        this->setPalette(palette); //Method is called on the main window (.this) to set the palette
    } else {
        // Handle error loading the image, used for debugging
        qDebug() << "Error loading background image.";
    }
    update(); // Re-draws anything if needed, used as a preventive
}

//The argument is the QPaintEvent object, which provides info about the region painted
void MainWindow::paintEvent(QPaintEvent *event) {
    int h = 45;
    QPainter painter(this);
    int halfWidth = this->width()/2;
    int height = this->height() - h;

    QRect rectangleFirstPortion(0, height, halfWidth, h);// Color left side of rectangle
    QBrush rectangleFirstColor(Qt::black); //Define the color of the rectangle

    QRect rectangleSecondPortion(halfWidth, height, width(), h); //Color right side of rectangle
    QBrush rectangleSecondColor(Qt::white);

    painter.fillRect(rectangleFirstPortion, rectangleFirstColor); // Paint the rectangle portion with the rectangle color
    painter.fillRect(rectangleSecondPortion, rectangleSecondColor); // Paint second portion



    int boxHeightWindow = this->height() - 530; //Where the text will be placed in screen
    int leftStart = 450; // Text starts 25px from the left side of the screen
    int imageStart = 25; //What point in the screen the image will be placed (horizontal)
    int heightOfText = 50; // Height of the text box
    int heightOfSong = 275;
    float boxWidth = 2.45;

    QString boxText = "Name of Song";

    QRect rectangleSong (leftStart, boxHeightWindow, width()/boxWidth, heightOfText );
    QRect songImageBox (imageStart, boxHeightWindow, width()/boxWidth, heightOfSong);

    painter.drawText(rectangleSong, Qt::AlignCenter, boxText);

    QPixmap songImage ("/Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/Images/Oppenheimer.png");
    painter.drawPixmap (songImageBox, songImage);

}



void MainWindow::Menus(){
    /*
     * Here we will have logic for the menu such as song image and title of song
     */
}

void MainWindow::Toolbars() {

}

void MainWindow::StatusBar() {

}


