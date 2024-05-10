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

    QString title = "Coding Sesh Player";
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
}



void MainWindow::Menus(){

}

void MainWindow::Toolbars() {

}

void MainWindow::StatusBar() {

}


