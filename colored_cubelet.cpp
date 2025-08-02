#include "colored_cubelet.h"

void CubeletFace::coloring(const Color color)
{
    this->color = color;
}

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

void ColoredCubelet::rotateColorXClockwise()
{
    rotateXClockwise();
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
