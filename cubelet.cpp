#include "cubelet.h"

Cubelet::Cubelet(const int x, const int y, const int z) :
    position(x, y, z)
{
}

void Cubelet::rotateXClockwise(const Angle angle)
{
    position = position.rotateX(angle);
}

void Cubelet::rotateYClockwise(const Angle angle)
{
    position = position.rotateY(angle);
}

void Cubelet::rotateZClockwise(const Angle angle)
{
    position = position.rotateZ(angle);
}
