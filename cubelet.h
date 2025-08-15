#pragma once

#include "position.h"


class Cubelet
{
public:
    virtual ~Cubelet() = default;
    Position position;

    Cubelet(int x, int y, int z);

protected:
    virtual void rotateXClockwise(Angle angle);
    virtual void rotateYClockwise(Angle angle);
    virtual void rotateZClockwise(Angle angle);
};
