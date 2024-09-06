# QT Simple Sample

A simple Qt application demonstrating the basic usage of `QMainWindow`, signal and slot mechanisms, and UI management using the Qt Designer. The project uses CMake for building, and it increments a counter displayed in the UI, with options to reset it to zero.

## Table of Contents
- [Project Overview](#project-overview)
- [Features](#features)
- [Usage](#usage)
- [Project Structure](#project-structure)


---

## Project Overview

This project showcases how to build a simple desktop application with Qt, utilizing the core concepts of the framework, including:
- **QMainWindow**: The main window of the application.
- **Signals and Slots**: For handling button clicks and updating the UI.
- **Qt Designer**: For defining the UI layout.
- **CMake**: A modern build system to compile the project.

The app contains an increment button that increases a counter displayed on the screen, and a reset button to set the counter back to zero.

---

## Features

- Increment a displayed counter using a button.
- Reset the counter to zero with a separate button.
- Simple and clean user interface (UI) created using **Qt Designer**.
- Cross-platform with support for Linux, Windows, and macOS using **CMake**.

---

## Usage

- Click the "Increment" button to increase the counter.
- Click the "Reset" button to reset the counter to 0.

This application is a simple demonstration of how signals and slots work in Qt.

---

## Project Structure

Here's a breakdown of the project structure:

- **CMakeLists.txt**: CMake configuration for building the project
- **main.cpp**: Entry point of the application
- **mainwindow.cpp**: Implementation of the MainWindow class
- **mainwindow.h**: Declaration of the MainWindow class
- **mainwindow.ui**: UI file defining the layout and design of the window
- **.gitignore**: Files and directories to be ignored by Git
- **README.md**: This file


### Key Files:

- **CMakeLists.txt**: Configures CMake to build the Qt application.
- **main.cpp**: Contains the `main()` function, which is the entry point of the program.
- **mainwindow.cpp/h**: Implements and declares the `MainWindow` class, which handles the UI logic.
- **mainwindow.ui**: UI layout created with Qt Designer.

---

