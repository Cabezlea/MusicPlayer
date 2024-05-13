//This is where we define the class functions do
#include "MainWindow.h"
#include <QMenuBar>
#include <QLabel>
#include <QWidget>
#include <Qpainter>
#include <QIcon>
#include <QPushButton>
#include <QHBoxLayout>


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
    /*
     * Here we will have the logic for the Toolbars such as skip, play, pause, etc.
     */

    int toolbarsHeight = 30;
    float toolbarsWidth = width()/8;
    int spaceBetween = -400;
    int buttonSize;

    //Instance of the outer layout
    QHBoxLayout *outerLayout = new QHBoxLayout;

    //Setting positions using inner layout
    QHBoxLayout *innerLayout1 = new QHBoxLayout;
    QHBoxLayout *innerLayout2 = new QHBoxLayout;
    QHBoxLayout *innerLayout3 = new QHBoxLayout;
    QHBoxLayout *innerLayout4 = new QHBoxLayout;


    //Creating instances of the buttons, they are pointers because they need to be dynamic since we will be constantly updating the buttons

    QPushButton *playButton = new QPushButton(this);
    QPushButton *pauseButton = new QPushButton(this);
    QPushButton *skipButton = new QPushButton(this);
    QPushButton *backwardsButton = new QPushButton(this);

    //Setting the images for each button
    playButton->setIcon(QIcon("/Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/Images/PlayButton.png"));
    pauseButton->setIcon(QIcon("/Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/Images/PauseButton.png"));
    skipButton->setIcon(QIcon("/Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/Images/SkipForward.png"));
    backwardsButton->setIcon(QIcon("/Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/Images/BackwardsButton.png"));

    //Set fixed sizes for each button
    playButton->setFixedSize(toolbarsWidth, toolbarsHeight);
    pauseButton->setFixedSize(toolbarsWidth, toolbarsHeight);
    skipButton->setFixedSize(toolbarsWidth, toolbarsHeight);
    backwardsButton->setFixedSize(toolbarsWidth, toolbarsHeight);

    innerLayout1->addWidget(backwardsButton);
    innerLayout1->addSpacing(spaceBetween);
    innerLayout2->addWidget(playButton);
    innerLayout2->addSpacing(spaceBetween);
    innerLayout3->addWidget(pauseButton);
    innerLayout3->addSpacing(spaceBetween);
    innerLayout4->addWidget(skipButton);
    innerLayout4->addSpacing(spaceBetween);

    outerLayout->addLayout(innerLayout1);
    outerLayout->addLayout(innerLayout2);
    outerLayout->addLayout(innerLayout3);
    outerLayout->addLayout(innerLayout4);


    //Set outer Layout on a conteiner wdiget, organizing all containing widgets
    this->setLayout(outerLayout);

    //Connecting the buttons to functions using clicked()

}
void MainWindow::StatusBar() {

}
