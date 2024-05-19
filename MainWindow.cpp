//This is where we define the class functions do
#include "MainWindow.h"
#include <QMenuBar>
#include <QLabel>
#include <QWidget>
#include <Qpainter>
#include <QIcon>
#include <QPushButton>
#include <QHBoxLayout>
#include <QProgressBar>
#include <QSlider>


MainWindow::MainWindow() {
    Menus();
    Toolbars();
    StatusBar();

    QString title = "Open Source Music Player in C++";
    setWindowTitle(title);

    resize(800,600); //Screen size
    // Load the background image using the absolute file path
    //QPixmap is a class provided by QT to handle images in applications, we create an object named bkgnd
    QPixmap bkgnd("/Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/Images/InterstellarImage.png"); // Replace "/home/user/Pictures/background.png" with the actual path to your image file

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
    int imageStart = 25; //What points in the screen the image will be placed (horizontal)
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
     * Here we will have UI for the menu such as song image and title of song
     */
}

void MainWindow::Toolbars() {
     /*
      * Here we will have the UI for the Toolbars such as skip, play, pause, etc.
      */

    // Creating instances of the buttons
    QPushButton *backwardsButton = new QPushButton(this);
    QPushButton *playButton = new QPushButton(this);
    QPushButton *pauseButton = new QPushButton(this);
    QPushButton *skipButton = new QPushButton(this);

    // Setting the icons for each button
    backwardsButton->setIcon(QIcon("/Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/Images/BackwardsButton.png"));
    playButton->setIcon(QIcon("/Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/Images/PlayButton.png"));
    pauseButton->setIcon(QIcon("/Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/Images/PauseButton.png"));
    skipButton->setIcon(QIcon("/Users/user/Dropbox/Mac/Desktop/Projects/C++/PersonalProj/musicPlayer/Images/SkipForward.png"));

    // Set fixed sizes for each button
    int buttonWidth = 120; //55
    int buttonHeight = 50; //35
    int startX = 150; // Starting x-coordinate for the first button
    int startY = 390; // y-coordinate for all buttons

    // Positioning each button in the desired order: Backwards, Play, Pause, Skip
    // Next button is calculated by startX + buttonWidth + spacing
    backwardsButton->setGeometry(startX, startY, buttonWidth, buttonHeight);
    playButton->setGeometry(startX + buttonWidth + 5, startY, buttonWidth, buttonHeight); //5 Pixels to the right and one button width
    pauseButton->setGeometry(startX + 2 * (buttonWidth + 5), startY, buttonWidth, buttonHeight); //Two button widths and 2 spaces before we are stacking 2 buttons and 2 spaces before this button
    skipButton->setGeometry(startX + 3 * (buttonWidth + 5), startY, buttonWidth, buttonHeight); //3 buttonWidths and 3 spaces to start x

    //New Size for icons
    QSize iconSize(75,45);
    backwardsButton->setIconSize(iconSize);
    playButton->setIconSize(iconSize);
    pauseButton->setIconSize(iconSize);
    skipButton->setIconSize(iconSize);

    //use setStyleSheet to remove the background from each button
    playButton->setStyleSheet("QPushButton { border: none; background-color: transparent; }" //Set property when button is static
                              "QPushButton:hover { cursor: pointer; background-color: rgba(255, 255, 255, 0.1); }" //When button is hovered
                              "QPushButton:pressed { background-color: rgba(255, 255, 255, 0.2); }"); //When button is pressed
    playButton->setCursor(Qt::PointingHandCursor);

    pauseButton->setStyleSheet("QPushButton { border: none; background-color: transparent; }"
                               "QPushButton:hover { cursor: pointer; background-color: rgba(255, 255, 255, 0.1); }"
                               "QPushButton:pressed { background-color: rgba(255, 255, 255, 0.2); }");
    pauseButton->setCursor(Qt::PointingHandCursor);

    skipButton->setStyleSheet("QPushButton { border: none; background-color: transparent; }"
                              "QPushButton:hover { cursor: pointer; background-color: rgba(255, 255, 255, 0.1); }"
                              "QPushButton:pressed { background-color: rgba(255, 255, 255, 0.2); }");
    skipButton->setCursor(Qt::PointingHandCursor);

    backwardsButton->setStyleSheet("QPushButton { border: none; background-color: transparent; }"
                                   "QPushButton:hover { cursor: pointer; background-color: rgba(255, 255, 255, 0.1); }"
                                   "QPushButton:pressed { background-color: rgba(255, 255, 255, 0.2); }");
    backwardsButton->setCursor(Qt::PointingHandCursor);

}


void MainWindow::StatusBar() {
    /*
     * In this method we will create the UI for the song status bar and the bar to adjust the volume
     */
    QSlider *songStatusBar = new QSlider(Qt::Horizontal,this);
    songStatusBar->setRange(0,100); //Range of song
    songStatusBar->setValue(80); //Initial value
    songStatusBar->setGeometry(470,170,275,20);

    //Now we will create the volume bar in here to adjust it

    songStatusBar->setStyleSheet(R"(
        QSlider::groove:horizontal {
            border: 1px solid #b1b1b1;
            background: #f3f3f3;
            height: 4px;
            border-radius: 2px;
        }
        QSlider::handle:horizontal {
            background: #5CACEE;
            border: 1px solid #5CACEE;
            width: 10px;
            height: 10px;
            margin: -3px 0;
            border-radius: 5px;
        }
        QSlider::sub-page:horizontal {
            background-color: #5CACEE;
            border-radius: 2px;
        }
        QSlider::add-page:horizontal {
            background-color: #b1b1b1;
            border-radius: 2px;
        }
    )");

    // Labels for the start and end times
    QLabel *startLabel = new QLabel("0:00", this);
    QLabel *endLabel = new QLabel("4:30", this);

    startLabel->setGeometry(470, 150, 40, 20); // Adjust position to line up with the start of the slider
    endLabel->setGeometry(715, 150, 40, 20); // Adjust position to line up with the end of the slider

    startLabel->show();
    endLabel->show();
    songStatusBar->show();

    QSlider *volumeSlider = new QSlider(Qt::Horizontal,this);
    volumeSlider->setRange(0,100); //Range of song
    volumeSlider->setValue(50); //Initial value
    volumeSlider->setGeometry(470,320,275,20);

}
