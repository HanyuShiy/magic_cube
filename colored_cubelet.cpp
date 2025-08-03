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

Position ColoredCubelet::getPosition() const
{
    return Position{this->position.x, this->position.y, this->position.z};
}

void ColoredCubelet::rotateXClockwise()
{
    Cubelet::rotateXClockwise();
    for (auto& face : faces)
    {
        face.rotateXClockwise();
    }
}
