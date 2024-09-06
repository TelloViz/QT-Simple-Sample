cmake_minimum_required(VERSION 3.16)  # Set the minimum required CMake version for this project.

project(sample_program VERSION 0.1 LANGUAGES CXX)  # Define the project name, version, and programming languages used.

set(CMAKE_AUTOUIC ON)  # Enable automatic handling of Qt's User Interface Compiler (uic) files.
set(CMAKE_AUTOMOC ON)  # Enable automatic handling of Qt's Meta-Object Compiler (moc) files.
set(CMAKE_AUTORCC ON)  # Enable automatic handling of Qt's Resource Compiler (rcc) files.

set(CMAKE_CXX_STANDARD 17)  # Set the C++ standard to C++17.
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # Ensure that the C++17 standard is used.

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)  # Locate the Qt package, requiring the Widgets module.
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)  # Locate the appropriate Qt version (Qt5 or Qt6) and ensure the Widgets module is available.

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)  # List the source files and UI files for the project.

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(sample_program
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        .gitignore
    )  # Create an executable target using Qt 6 and list the source files.

    # Define target properties for Android with Qt 6 as:
    # set_property(TARGET sample_program APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
    #              ${CMAKE_CURRENT_SOURCE_DIR}/android)
    # For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(sample_program SHARED
            ${PROJECT_SOURCES}
        )  # Create a shared library target for Android with Qt 5 and list the source files.
        # Define properties for Android with Qt 5 after find_package() calls as:
        # set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(sample_program
            ${PROJECT_SOURCES}
        )  # Create an executable target for other platforms with Qt 5 and list the source files.
    endif()
endif()

target_link_libraries(sample_program PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)  # Link the Qt Widgets library to the executable target.

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.sample_program)  # Set bundle identifier for macOS applications.
endif()

set_target_properties(sample_program PROPERTIES
    ${BUNDLE_ID_OPTION}  # Apply the bundle identifier if set.
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}  # Set the bundle version for macOS.
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}  # Set the short version string for macOS.
    MACOSX_BUNDLE TRUE  # Mark the target as a macOS bundle.
    WIN32_EXECUTABLE TRUE  # Mark the target as a Windows executable.
)

include(GNUInstallDirs)  # Include standard directory variables for installation paths.

install(TARGETS sample_program
    BUNDLE DESTINATION .  # Install bundle files to the current directory.
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}  # Install library files to the library directory.
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}  # Install runtime files to the binary directory.
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(sample_program)  # Finalize the executable target if using Qt 6.
endif()

#
# Description of Each Section:
#
# CMake Minimum Version:
#     Specifies the minimum required version of CMake for this project.
#
# Project Declaration:
#     Declares the project name, version, and programming languages used.
#
# Automatic Handling:
#     CMake settings to automatically handle Qt .ui, .qrc, and moc files.
#
# Find Qt Package:
#     Locates the Qt package and ensures the required components are available.
#
# Source Files:
#     Lists the source files for the project, including implementation (.cpp), header (.h), and UI (.ui) files.
#
# Executable Definition:
#     Defines how to create the executable or library. Handles different Qt versions and Android-specific settings.
#
# Linking Libraries:
#     Links the necessary Qt Widgets library to the project.
#
# Bundle Identifier:
#     Sets properties for macOS and iOS applications, including bundle version and identifiers.
#
# Installation:
#     Specifies installation paths for different types of files.
#
# Finalize Executable:
#     Finalizes the executable settings if using Qt 6.
#
