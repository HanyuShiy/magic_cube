#include "angle.h"

#pragma once

class Position
{
    static int normalize(int const value);

public:
    int x, y, z;

    Position(int x, int y, int z);

    Position rotateX(Angle angle) const;
    Position rotateY(Angle angle) const;
    Position rotateZ(Angle angle) const;
};
