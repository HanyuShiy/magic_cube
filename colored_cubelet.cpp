#include "colored_cubelet.h"


ColoredCubelet::ColoredCubelet(const int x, const int y, const int z):
    Cubelet(x, y, z),
    faces{
        {
            CubeletFace(FRONT_ORIENTATED),
            CubeletFace(BACK_ORIENTATED),
            CubeletFace(TOP_ORIENTATED),
            CubeletFace(BOTTOM_ORIENTATED),
            CubeletFace(LEFT_ORIENTATED),
            CubeletFace(RIGHT_ORIENTATED)
        }
    }
{
}

void ColoredCubelet::coloring(const Orientation orientation, const Color color)
{
    for (auto& face : faces)
    {
        if (face.orientation == orientation)
        {
            face.coloring(color);
        }
    }
}

Color ColoredCubelet::getFaceOn(const Orientation orientation) const
{
    for (auto face : faces)
    {
        if (face.orientation == orientation)
        {
            return face.color;
        }
    }
    throw;
}


void ColoredCubelet::rotateXClockwise()
{
    Cubelet::rotateXClockwise();
    for (auto& face : faces)
    {
        face.rotateXClockwise();
    }
}

void ColoredCubelet::rotateYClockwise()
{
    Cubelet::rotateYClockwise();
    for (auto& face : faces)
    {
        face.rotateYClockwise();
    }
}

void ColoredCubelet::rotateZClockwise()
{
    Cubelet::rotateZClockwise();
    for (auto& face : faces)
    {
        face.rotateZClockwise();
    }
}

void ColoredCubelet::rotateAround(const Orientation axis)
{


    if (axis == FRONT_ORIENTATED || axis == BACK_ORIENTATED)
    {
        rotateXClockwise();
    }
    if (axis == LEFT_ORIENTATED || axis == RIGHT_ORIENTATED)
    {
        rotateZClockwise();
    }
    if (axis == TOP_ORIENTATED || axis == BOTTOM_ORIENTATED)
    {
        rotateZClockwise();
    }
}
