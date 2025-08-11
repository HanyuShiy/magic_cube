#include "colored_cubelet.h"


ColoredCubelet::ColoredCubelet(const int x, const int y, const int z) :
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
    for (auto& face : faces)
    {
        if (face.orientation == orientation)
        {
            return face.color;
        }
    }
    throw;
}


void ColoredCubelet::rotateXClockwise(const Angle angle)
{
    Cubelet::rotateXClockwise(angle);
    for (auto& face : faces)
    {
        face.rotateXClockwise(angle);
    }
}

void ColoredCubelet::rotateYClockwise(const Angle angle)
{
    Cubelet::rotateYClockwise(angle);
    for (auto& face : faces)
    {
        face.rotateYClockwise(angle);
    }
}

void ColoredCubelet::rotateZClockwise(const Angle angle)
{
    Cubelet::rotateZClockwise(angle);
    for (auto& face : faces)
    {
        face.rotateZClockwise(angle);
    }
}

bool ColoredCubelet::isEdge() const
{
    int i = 0;
    for (const auto& face : faces)
    {
        if (face.color != EMPTY)
        {
            i++;
        }
    }
    if (i == 2)
    {
        return true;
    }
    return false;
}

bool ColoredCubelet::isCorner() const
{
    int i = 0;
    for (const auto& face : faces)
    {
        if (face.color != EMPTY)
        {
            i++;
        }
    }
    if (i == 3)
    {
        return true;
    }
    return false;
}

void ColoredCubelet::rotateAround(const Orientation& axis, const Angle& angle)
{
    if (axis == Orientation{1, 0, 0})
    {
        rotateXClockwise(angle);
    }
    if (axis == Orientation{0, 1, 0})
    {
        rotateYClockwise(angle);
    }
    if (axis == Orientation{0, 0, 1})
    {
        rotateZClockwise(angle);
    }
}
