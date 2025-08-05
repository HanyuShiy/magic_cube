#include "position.h"

#pragma once

class Cubelet
{
public:
    virtual ~Cubelet() = default;
    Position position;

    Cubelet(int x, int y, int z);

protected:
    virtual void rotateXClockwise();
    virtual void rotateYClockwise();
    virtual void rotateZClockwise();
};
