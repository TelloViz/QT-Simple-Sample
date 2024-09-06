#include "mainwindow.h"
#include <QApplication>

// Description: Entry point of the Qt application. Sets up the QApplication object and displays the MainWindow.

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);  // Create the QApplication object, which manages application-wide resources and settings
    MainWindow w;                // Create the MainWindow object
    w.show();                    // Display the MainWindow
    return a.exec();             // Enter the Qt event loop and wait until exit() is called
}

/*

Description of Each Section:

QApplication a(argc, argv):
    Creates an instance of QApplication, which is required for any Qt application. It manages application-wide resources and settings.

MainWindow w:
    Creates an instance of the MainWindow class, which represents the main application window.

w.show():
    Displays the MainWindow to the user.

return a.exec():
    Enters the Qt event loop, which waits for and processes events. This call blocks until the event loop exits, which typically happens when the application is closed.

*/
