#include "position.h"

#pragma once

class Cubelet
{
public:
    Position position;

    Cubelet(int x, int y, int z);

    bool onFrontFace() const;
    bool onBackFace() const;
    bool onLeftFace() const;
    bool onRightFace() const;
    bool onTopFace() const;
    bool onBottomFace() const;

protected:
    virtual void rotateXClockwise();
    virtual void rotateYClockwise();
    virtual void rotateZClockwise();
};
