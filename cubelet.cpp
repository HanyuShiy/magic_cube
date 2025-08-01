#include "cubelet.h"

Cubelet::Cubelet(const int x, const int y, const int z):
    position(x, y, z), orientation(ANGLE_ZERO, ANGLE_ZERO, ANGLE_ZERO)
{
}

void Cubelet::rotateXClockwise()
{
    position = position.rotateX(ONE_STEP_CLOCKWISE);
    orientation = orientation.rotateX(ONE_STEP_CLOCKWISE);
}

void Cubelet::rotateYClockwise()
{
    position = position.rotateY(ONE_STEP_CLOCKWISE);
    orientation = orientation.rotateY(ONE_STEP_CLOCKWISE);
}

void Cubelet::rotateZClockwise()
{
    position = position.rotateZ(ONE_STEP_CLOCKWISE);
    orientation = orientation.rotateZ(ONE_STEP_CLOCKWISE);
}

bool Cubelet::onFrontFace() const
{
    return position.x == 1;
}

bool Cubelet::onBackFace() const
{
    return position.x == -1;
}

bool Cubelet::onLeftFace() const
{
    return position.y == 1;
}

bool Cubelet::onRightFace() const
{
    return position.y == -1;
}

bool Cubelet::onTopFace() const
{
    return position.z == 1;
}

bool Cubelet::onBottomFace() const
{
    return position.z == -1;
}
