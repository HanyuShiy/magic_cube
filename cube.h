#pragma once
#include "face.h"
#include "layer.h"

class Cube
{
public:
    ColoredCubelet cubelets[26];

    Cube();

    void coloring();

    [[nodiscard]] Face getFront();
    [[nodiscard]] Face getBack();
    [[nodiscard]] Face getLeft();
    [[nodiscard]] Face getRight();
    [[nodiscard]] Face getTop();
    [[nodiscard]] Face getBottom();

    Cube& rotateClockwise(const Layer& layer, int steps = 1);
};
