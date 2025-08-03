#include "orientation.h"

Orientation::Orientation(const int x, const int y, const int z):
    x(x), y(y), z(z)
{
}

Orientation Orientation::rotateX(const Angle angle) const
{
    int newY_ = y * Angle::cos(angle) + z * Angle::sin(angle);
    int newZ_ = z * Angle::cos(angle) - y * Angle::sin(angle);
    return {x, newY_, newZ_};
}

Orientation Orientation::rotateY(const Angle angle) const
{
    int newX_ = x * Angle::cos(angle) - z * Angle::sin(angle);
    int newZ_ = x * Angle::sin(angle) + z * Angle::cos(angle);
    return {newX_, y, newZ_};
}

Orientation Orientation::rotateZ(const Angle angle) const
{
    int newX_ = -y * Angle::sin(angle) + x * Angle::cos(angle);
    int newY_ = y * Angle::cos(angle) - x * Angle::sin(angle);
    return {newX_, newY_, z};
}

bool Orientation::operator==(const Orientation& that) const
{
    return this->x == that.x && this->y == that.y && this->z == that.z;
}


