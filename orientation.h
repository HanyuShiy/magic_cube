#pragma once
#include "angle.h"

class Orientation
{
public:
    Angle roll, pitch, yaw;

    Orientation(Angle roll, Angle pitch, Angle yaw);

    Orientation rotateX(const Angle angle) const;
    Orientation rotateY(const Angle angle) const;
    Orientation rotateZ(const Angle angle) const;
};

const auto FRONT_ORIENTATED = Orientation{ANGLE_ZERO, ANGLE_ZERO, ANGLE_ZERO};
const auto BACK_ORIENTATED = Orientation{ANGLE_ZERO, ANGLE_ZERO, HALF_ROUND};
const auto TOP_ORIENTATED = Orientation{ANGLE_ZERO, ONE_STEP_COUNTERCLOCKWISE, ANGLE_ZERO};
const auto BOTTOM_ORIENTATED = Orientation{ANGLE_ZERO, ONE_STEP_CLOCKWISE, ANGLE_ZERO};
const auto LEFT_ORIENTATED = Orientation{ANGLE_ZERO, ANGLE_ZERO, ONE_STEP_CLOCKWISE};
const auto RIGHT_ORIENTATED = Orientation{ANGLE_ZERO, ANGLE_ZERO, ONE_STEP_COUNTERCLOCKWISE};
