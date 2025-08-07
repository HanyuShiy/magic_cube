#include "position.h"

int Position::normalize(int const value)
{
    if (0 == value)
    {
        return 0; // Center position
    }
    return value > 0 ? 1 : -1; // Positive direction
}

Position::Position(const int x, const int y, const int z):
    x(normalize(x)),
    y(normalize(y)),
    z(normalize(z))
{
}

Position Position::rotateX(const Angle& angle) const
{
    // Rotate around X-axis
    const int newY = y * Angle::cos(angle) + z * Angle::sin(angle);
    const int newZ = -y * Angle::sin(angle) + z * Angle::cos(angle);
    return {x, newY, newZ};
}

Position Position::rotateY(const Angle& angle) const
{
    // Rotate around Y-axis
    const int newX = x * Angle::cos(angle) - z * Angle::sin(angle);
    const int newZ = x * Angle::sin(angle) + z * Angle::cos(angle);
    return {newX, y, newZ};
}

Position Position::rotateZ(const Angle& angle) const
{
    // Rotate around Z-axis
    const int newY = y * Angle::cos(angle) - x * Angle::sin(angle);
    const int newX = y * Angle::sin(angle) + x * Angle::cos(angle);
    return {newX, newY, z};
}
