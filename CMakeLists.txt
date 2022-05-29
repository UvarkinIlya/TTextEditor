cmake_minimum_required(VERSION 3.20)
project(TextEditor)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled2 main.cpp TNode.cpp TNode.h TText.cpp TText.h Viewer.cpp Viewer.h Viewer2.cpp temp.cpp TTextMem.cpp TTextMem.h)