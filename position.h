#pragma once

#include "angle.h"

class Position
{
    static int normalize(int value);

public:
    int x, y, z;

    Position(int x, int y, int z);

    [[nodiscard]] Position rotateX(const Angle& angle) const;
    [[nodiscard]] Position rotateY(const Angle& angle) const;
    [[nodiscard]] Position rotateZ(const Angle& angle) const;
};
