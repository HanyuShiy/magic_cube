#include "cubelet_face.h"

CubeletFace::CubeletFace(const Orientation& orientation) :
    color(Color::EMPTY),
    orientation(orientation)
{
}

CubeletFace::CubeletFace() : color(EMPTY), orientation(DEFAULT_ORIENTATION)
{
}

void CubeletFace::coloring(const Color color)
{
    this->color = color;
}

void CubeletFace::rotateXClockwise(const Angle angle)
{
    const auto afterRotation = this->orientation.rotateX(angle);
    this->orientation = afterRotation;
}

void CubeletFace::rotateYClockwise(const Angle angle)
{
    const auto afterRotation = this->orientation.rotateY(angle);
    this->orientation = afterRotation;
}

void CubeletFace::rotateZClockwise(const Angle angle)
{
    const auto afterRotation = this->orientation.rotateZ(angle);
    this->orientation = afterRotation;
}

Orientation& CubeletFace::findColor(const Color color)
{
    if (this->color == color)
    {
        return orientation;
    }
    throw;
}
