#pragma once
#include "angle.h"

class Position
{
    static int normalize(int const value)
    {
        if (0 == value)
        {
            return 0; // Center position
        }
        return value > 0 ? 1 : -1; // Positive direction
    }

public:
    int x, y, z;

    Position(const int x, const int y, const int z);

    Position rotateX(const Angle angle) const;
    Position rotateY(const Angle angle) const;
    Position rotateZ(const Angle angle) const;
};
