#pragma once
#include "angle.h"

class Orientation
{
public:
    Angle roll, pitch, yaw;

    Orientation(const Angle roll, const Angle pitch, const Angle yaw) : roll(roll), pitch(pitch), yaw(yaw)
    {
    }

    Orientation rotateX(const Angle angle) const
    {
        return {roll.add(angle), pitch, yaw};
    }

    Orientation rotateY(const Angle angle) const
    {
        return {roll, pitch.add(angle), yaw};
    }

    Orientation rotateZ(const Angle angle) const
    {
        return {roll, pitch, yaw.add(angle)};
    }
};
