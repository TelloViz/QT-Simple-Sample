#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// Description: Header file for the MainWindow class in a Qt application.
// This file defines the MainWindow class, which is a subclass of QMainWindow,
// and provides the declarations for its public and private members. It includes
// declarations for slots (event handlers) and member variables used in the main window.

#include <QMainWindow> // Include the QMainWindow class from Qt, which provides the main window functionality

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; } // Forward declaration of the Ui namespace, which contains the MainWindow class definition
QT_END_NAMESPACE

// MainWindow class definition
class MainWindow : public QMainWindow
{
    Q_OBJECT // Macro for Qt's Meta-Object Compiler (MOC) to enable signal and slot mechanism

public:
    // Constructor: Initializes the MainWindow object
    // Parameters:
    //   parent - Optional pointer to a parent QWidget; defaults to nullptr if not provided
    MainWindow(QWidget *parent = nullptr);

    // Destructor: Cleans up resources used by MainWindow
    ~MainWindow();

private slots:
    // Slot for handling the click event of the increment button
    void incrementClicked();  // Renamed from on_incrementButton_clicked

    // Slot for handling the click event of the reset button
    void resetClicked();      // Renamed from on_resetButton_clicked

private:
    Ui::MainWindow *ui; // Pointer to the Ui::MainWindow class, which manages the UI components of the MainWindow
    int count;          // Integer to keep track of a counter value
};

#endif // MAINWINDOW_H

/*

Description of Each Section:

Include Guards (#ifndef, #define, #endif):
    Prevent multiple inclusions of this header file, which can cause compilation errors.

Include Directive (#include <QMainWindow>):
    Includes the base class QMainWindow from Qt, which provides the functionality for the main application window.

Namespace Declaration (QT_BEGIN_NAMESPACE, QT_END_NAMESPACE):
    Encapsulates the Ui namespace declaration to avoid name clashes.

Class Definition (MainWindow):

Public Section:

    Constructor (MainWindow(QWidget *parent = nullptr)):
        Initializes the MainWindow object, with an optional parent widget.

    Destructor (~MainWindow()):
        Cleans up any resources allocated by the MainWindow.

Private Slots Section:

    Slot for Increment Button (incrementClicked()):
        Handles the click event for an increment button (e.g., updates a counter).

    Slot for Reset Button (resetClicked()):
        Handles the click event for a reset button (e.g., resets the counter).

Private Members:

    UI Pointer (Ui::MainWindow *ui):
        Pointer to the Ui::MainWindow class, which manages the UI components.

    Count Variable (int count):
        Stores the current counter value, used in the button slot implementations.

*/
