#include "orientation.h"

Orientation::Orientation(const int x, const int y, const int z) :
    x(x), y(y), z(z)
{
}

Orientation Orientation::rotateX(const Angle& angle) const
{
    int newY = y * Angle::cos(angle) + z * Angle::sin(angle);
    int newZ = z * Angle::cos(angle) - y * Angle::sin(angle);
    return {x, newY, newZ};
}

Orientation Orientation::rotateY(const Angle& angle) const
{
    int newX = x * Angle::cos(angle) - z * Angle::sin(angle);
    int newZ = x * Angle::sin(angle) + z * Angle::cos(angle);
    return {newX, y, newZ};
}

Orientation Orientation::rotateZ(const Angle& angle) const
{
    int newX = y * Angle::sin(angle) + x * Angle::cos(angle);
    int newY = y * Angle::cos(angle) - x * Angle::sin(angle);
    return {newX, newY, z};
}
