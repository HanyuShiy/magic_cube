#include "cubelet_face.h"

bool CubeletFace::isColored() const
{
    if (color != EMPTY)
    {
        return true;
    }
    return false;
}

CubeletFace::CubeletFace(const Orientation& orientation):
    color(Color::EMPTY),
    orientation(orientation)
{
}

void CubeletFace::coloring(const Color color)
{
    this->color = color;
}

void CubeletFace::rotateXClockwise()
{
    const auto afterRotation = this->orientation.rotateX(ONE_STEP_CLOCKWISE);
    this->orientation = afterRotation;
}

void CubeletFace::rotateYClockwise()
{
    const auto afterRotation = this->orientation.rotateY(ONE_STEP_CLOCKWISE);
    this->orientation = afterRotation;
}

void CubeletFace::rotateZClockwise()
{
    const auto afterRotation = this->orientation.rotateZ(ONE_STEP_CLOCKWISE);
    this->orientation = afterRotation;
}
