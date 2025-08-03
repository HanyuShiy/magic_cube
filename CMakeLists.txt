cmake_minimum_required(VERSION 3.29)
project(magic_cube)

set(CMAKE_CXX_STANDARD 20)

add_executable(magic_cube
    main.cpp
        angle.cpp
        colored_cubelet.cpp
        cube.cpp
        face.cpp
        cubelet.cpp
        orientation.cpp
        position.cpp
        color.h
        cubelet_face.cpp)
