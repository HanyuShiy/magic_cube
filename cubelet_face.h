#pragma once
#include "color.h"
#include "orientation.h"

class CubeletFace
{
public:
    Color color;

    Orientation orientation;

    explicit CubeletFace(const Orientation& orientation);
    CubeletFace();

    void coloring(Color color);

    void rotateXClockwise(Angle angle);
    void rotateYClockwise(Angle angle);
    void rotateZClockwise(Angle angle);

    Orientation& findColor(Color color);
};
