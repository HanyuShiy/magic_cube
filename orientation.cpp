#include "orientation.h"

Orientation::Orientation(Angle roll, Angle pitch, Angle yaw) : roll(roll), pitch(pitch), yaw(yaw)
{
}

Orientation Orientation::rotateX(const Angle angle) const
{
    return {roll.add(angle), pitch, yaw};
}

Orientation Orientation::rotateY(const Angle angle) const
{
    return {roll, pitch.add(angle), yaw};
}

Orientation Orientation::rotateZ(const Angle angle) const
{
    return {roll, pitch, yaw.add(angle)};
}
