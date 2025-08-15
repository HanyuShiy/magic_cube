#pragma once
#include <map>
#include <functional>

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

    Cube& rotateClockwise(const Layer& layer, const Angle& angle = CLOCKWISE_90, int steps = 1);
    // rotate a given-degree-angle:
    Cube& rotateDegreeClockwise(const Layer& layer, const Angle& angle);

    Cube& scramble(int steps = 10);

    Cube& applyAlgo(const std::string& rotations);

    // Cube& solveWhiteCross();
};

inline const std::map<std::string, std::function<Cube&(Cube&)>> Rotation
{
    {"F", [](Cube& c)-> Cube& { return c.rotateClockwise(frontLayer, CLOCKWISE_90); }},
    {"B", [](Cube& c)-> Cube& { return c.rotateClockwise(backLayer, COUNTERCLOCKWISE_90); }},
    {"L", [](Cube& c)-> Cube& { return c.rotateClockwise(leftLayer, COUNTERCLOCKWISE_90); }},
    {"R", [](Cube& c)-> Cube& { return c.rotateClockwise(rightLayer, CLOCKWISE_90); }},
    {"U", [](Cube& c)-> Cube& { return c.rotateClockwise(topLayer, CLOCKWISE_90); }},
    {"D", [](Cube& c)-> Cube& { return c.rotateClockwise(bottomLayer, COUNTERCLOCKWISE_90); }},
    {"F'", [](Cube& c)-> Cube& { return c.rotateClockwise(frontLayer, COUNTERCLOCKWISE_90); }},
    {"B'", [](Cube& c)-> Cube& { return c.rotateClockwise(backLayer, CLOCKWISE_90); }},
    {"L'", [](Cube& c)-> Cube& { return c.rotateClockwise(leftLayer, CLOCKWISE_90); }},
    {"R'", [](Cube& c)-> Cube& { return c.rotateClockwise(rightLayer, COUNTERCLOCKWISE_90); }},
    {"U'", [](Cube& c)-> Cube& { return c.rotateClockwise(topLayer, COUNTERCLOCKWISE_90); }},
    {"D'", [](Cube& c)-> Cube& { return c.rotateClockwise(bottomLayer, CLOCKWISE_90); }}
};
