#include "position.h"
#include "orientation.h"

#pragma once

class Cubelet
{
public:
    Position position;
    Orientation orientation;

    Cubelet(const int x, const int y, const int z):
        position(x, y, z), orientation(ANGLE_ZERO, ANGLE_ZERO, ANGLE_ZERO)
    {
    }

    void rotateXClockwise()
    {
        position = position.rotateX(ONE_STEP_CLOCKWISE);
        orientation = orientation.rotateX(ONE_STEP_CLOCKWISE);
    }

    void rotateYClockwise()
    {
        position = position.rotateY(ONE_STEP_CLOCKWISE);
        orientation = orientation.rotateY(ONE_STEP_CLOCKWISE);
    }

    void rotateZClockwise()
    {
        position = position.rotateZ(ONE_STEP_CLOCKWISE);
        orientation = orientation.rotateZ(ONE_STEP_CLOCKWISE);
    }

protected:
    bool onFrontFace() const
    {
        return position.x == 1;
    }

    bool onBackFace() const
    {
        return position.x == -1;
    }

    bool onLeftFace() const
    {
        return position.y == 1;
    }

    bool onRightFace() const
    {
        return position.y == -1;
    }

    bool onTopFace() const
    {
        return position.z == 1;
    }

    bool onBottomFace() const
    {
        return position.z == -1;
    }
};
