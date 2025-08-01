#pragma once

#include "colored_cubelet.h"
#include "face.h"

class Cube
{
public:
    ColoredCubelet cubelets[26];
    // constructor to initialize 26 cubelets

    Cube();

    Face getFront();
    Face getBack();
    Face getLeft();
    Face getRight();
    Face getTop();
    Face getBottom();
};
