#pragma once
#include "angle.h"

class Orientation
{
public:
    Angle roll, pitch, yaw;

    Orientation(const Angle roll, const Angle pitch, const Angle yaw);

    Orientation rotateX(const Angle angle) const;
    Orientation rotateY(const Angle angle) const;
    Orientation rotateZ(const Angle angle) const;
};
