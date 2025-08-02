#include "angle.h"

int Angle::normalize(const int angle)
{
    return angle < 0 ? angle % 4 + 4 : angle % 4;
}

bool Angle::operator==(const Angle other)
{
    if (*this == other)
    {
        return true;
    }
}

Angle::Angle(const int value) : value(normalize(value))
{
}

Angle Angle::add(const Angle other) const
{
    return Angle(this->value + other.value);
}

int Angle::cos(Angle const angle)
{
    switch (angle.value)
    {
    case 0: return 1; // cos(0 * pi/2) = 1
    case 1: return 0; // cos(1 * pi/2) = 0
    case 2: return -1; // cos(2 * pi/2) = -1
    case 3: return 0; // cos(3 * pi/2) = 0
    default: throw;
    }
}

int Angle::sin(Angle const angle)
{
    switch (angle.value)
    {
    case 0: return 0; // sin(0 * pi/2) = 0
    case 1: return 1; // sin(1 * pi/2) = 1
    case 2: return 0; // sin(2 * pi/2) = 0
    case 3: return -1; // sin(3 * pi/2) = -1
    default: throw;
    }
}
