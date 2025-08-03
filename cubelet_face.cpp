#include "cubelet_face.h"

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
