#include "position.h"

Position::Position(const int x, const int y, const int z):
    x(normalize(x)),
    y(normalize(y)),
    z(normalize(z))
{
}

Position Position::rotateX(const Angle angle) const
{
    // Rotate around X-axis
    const int newY = y * Angle::cos(angle) + z * Angle::sin(angle);
    const int newZ = y * Angle::sin(angle) - z * Angle::cos(angle);
    return {x, newY, newZ};
}

Position Position::rotateY(const Angle angle) const
{
    // Rotate around Y-axis
    const int newX = x * Angle::cos(angle) - z * Angle::sin(angle);
    const int newZ = x * Angle::sin(angle) + z * Angle::cos(angle);
    return {newX, y, newZ};
}

Position Position::rotateZ(const Angle angle) const
{
    // Rotate around Z-axis
    const int newY = x * Angle::cos(angle) - y * Angle::sin(angle);
    const int newX = x * Angle::sin(angle) + y * Angle::cos(angle);
    return {newX, newY, z};
}
