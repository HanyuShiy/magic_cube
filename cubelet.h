#include "position.h"
#include "orientation.h"
#include "color.h"

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

    bool onFrontFace() const;
    bool onBackFace() const;
    bool onLeftFace() const;
    bool onRightFace() const;
    bool onTopFace() const;
    bool onBottomFace() const;

    virtual Color getFrontFace() const;
    virtual Color getBackFace() const;
    virtual Color getLeftFace() const;
    virtual Color getRightFace() const;
    virtual Color getTopFace() const;
    virtual Color getBottomFace() const;
};
