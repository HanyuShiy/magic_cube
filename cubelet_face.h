#pragma once
#include "color.h"
#include "orientation.h"

class CubeletFace
{
public:
    Color color;

    Orientation orientation;

    explicit CubeletFace(const Orientation& orientation);

    void coloring(Color color);

    void rotateXClockwise();
    void rotateYClockwise();
    void rotateZClockwise();
};
