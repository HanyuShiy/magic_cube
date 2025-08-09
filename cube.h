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

    const ColoredCubelet& getCubeletAt(Position position) const;

    Cube& resetZ0Layer(const Orientation& orientation);

    Cube& rotateClockwise(const Layer& layer, const Angle& angle = CLOCKWISE_90, int steps = 1);
    // rotate a given-degree-angle:
    Cube& rotateDegreeClockwise(const Layer& layer, const Angle& angle);

    Cube& scramble(int steps = 10);
};
