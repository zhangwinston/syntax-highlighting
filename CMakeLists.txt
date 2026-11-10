cmake_minimum_required(VERSION 3.21)

project(VSyntaxHighlighting VERSION 6.30.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(GNUInstallDirs)
include(GenerateExportHeader)

# Fork of vnotex/syntax-highlighting: keep the Qt 5.15 / Windows 7 build of
# VNote working. Upstream dropped Qt 5 when adopting the 6.30 numbering.
set(QT_DEFAULT_MAJOR_VERSION 6 CACHE STRING "Qt version to use (5 or 6), defaults to 6")
if(QT_DEFAULT_MAJOR_VERSION GREATER 5)
    find_package(Qt6 6.9 NO_MODULE REQUIRED COMPONENTS Core Gui Network)
else()
    find_package(Qt5 REQUIRED COMPONENTS Core Gui Network)
endif()
set(QT_VERSION_MAJOR ${QT_DEFAULT_MAJOR_VERSION})
find_package(Python 3 REQUIRED COMPONENTS Interpreter)

option(QRC_SYNTAX "Bundle the syntax definition files inside the library as resources" ON)
option(NO_STANDARD_PATHS "Skip lookup of syntax and theme definitions in QStandardPaths locations" OFF)

add_subdirectory(data)
add_subdirectory(src)
