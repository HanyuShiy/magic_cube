//
// Created by Hanyu Shi on 11.08.25.
//

#ifndef MAGIC_CUBE_ROTATION_H
#define MAGIC_CUBE_ROTATION_H
#include <map>

#include "cube.h"
// inline std::map<std::string, std::function<Cube&(Cube&)>> Rotation =
// {
//     "F", std::bind(&Cube::rotateClockwise, frontLayer, CLOCKWISE_90),
//     "B", std::bind(Cube::rotateClockwise, backLayer, CLOCKWISE_90),
//     "L", std::bind(Cube::rotateClockwise, leftLayer, CLOCKWISE_90),
//     "R", std::bind(Cube::rotateClockwise, rightLayer, CLOCKWISE_90),
//     "U", std::bind(Cube::rotateClockwise, topLayer, CLOCKWISE_90),
//     "D", std::bind(Cube::rotateClockwise, bottomLayer, CLOCKWISE_90),
//
//     "F'", std::bind(Cube::rotateClockwise, frontLayer, COUNTERCLOCKWISE_90),
//     "B'", std::bind(Cube::rotateClockwise, backLayer, COUNTERCLOCKWISE_90),
//     "L'", std::bind(Cube::rotateClockwise, leftLayer, COUNTERCLOCKWISE_90),
//     "R'", std::bind(Cube::rotateClockwise, rightLayer, COUNTERCLOCKWISE_90),
//     "U'", std::bind(Cube::rotateClockwise, topLayer, COUNTERCLOCKWISE_90),
//     "D'", std::bind(Cube::rotateClockwise, bottomLayer, COUNTERCLOCKWISE_90)
//
// };
const std::map<std::string, std::function<Cube&(Cube&)>> Rotation
{
    {"F", [](Cube& c) { return c.rotateClockwise(frontLayer, CLOCKWISE_90); }},
    {"B", [](Cube& c) { return c.rotateClockwise(backLayer, CLOCKWISE_90); }},
    {"L", [](Cube& c) { return c.rotateClockwise(leftLayer, CLOCKWISE_90); }},
    {"R", [](Cube& c) { return c.rotateClockwise(rightLayer, CLOCKWISE_90); }},
    {"U", [](Cube& c) { return c.rotateClockwise(topLayer, CLOCKWISE_90); }},
    {"D", [](Cube& c) { return c.rotateClockwise(bottomLayer, CLOCKWISE_90); }},

    {"F'", [](Cube& c) { return c.rotateClockwise(frontLayer, COUNTERCLOCKWISE_90); }},
    {"B'", [](Cube& c) { return c.rotateClockwise(backLayer, COUNTERCLOCKWISE_90); }},
    {"L'", [](Cube& c) { return c.rotateClockwise(leftLayer, COUNTERCLOCKWISE_90); }},
    {"R'", [](Cube& c) { return c.rotateClockwise(rightLayer, COUNTERCLOCKWISE_90); }},
    {"U'", [](Cube& c) { return c.rotateClockwise(topLayer, COUNTERCLOCKWISE_90); }},
    {"D'", [](Cube& c) { return c.rotateClockwise(bottomLayer, COUNTERCLOCKWISE_90); }}
};


#endif //MAGIC_CUBE_ROTATION_H
