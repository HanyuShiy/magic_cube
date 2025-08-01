#include "position.h"
#include "orientation.h"

#pragma once

class Cubelet
{
public:
    Position position;
    Orientation orientation;

    Cubelet(const int x, const int y, const int z);

    void rotateXClockwise();
    void rotateYClockwise();
    void rotateZClockwise();

protected:
    bool onFrontFace() const;
    bool onBackFace() const;
    bool onLeftFace() const;
    bool onRightFace() const;
    bool onTopFace() const;
    bool onBottomFace() const;
};
