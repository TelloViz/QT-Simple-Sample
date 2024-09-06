#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , count(0)  // Initialize the count to 0
{
    ui->setupUi(this);
    ui->label->setText(QString::number(count));  // Display the initial count
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_incrementButton_clicked()
{
    count++;
    ui->label->setText(QString::number(count));  // Update the label with the new count
}

void MainWindow::on_resetButton_clicked()
{
    count = 0;
    ui->label->setText(QString::number(count));  // Reset the count and update the label
}


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

    Slot for Increment Button (on_incrementButton_clicked()):
        Handles the click event for an increment button (e.g., updates a counter).

    Slot for Reset Button (on_resetButton_clicked()):
        Handles the click event for a reset button (e.g., resets the counter).

Private Members:

    UI Pointer (Ui::MainWindow *ui):
        Pointer to the Ui::MainWindow class, which manages the UI components.

    Count Variable (int count):
        Stores the current counter value, used in the button slot implementations.

*/
