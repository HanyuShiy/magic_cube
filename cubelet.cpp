#include "cubelet.h"

Cubelet::Cubelet(const int x, const int y, const int z):
    position(x, y, z)
{
}

void Cubelet::rotateXClockwise()
{
    position = position.rotateX(ONE_STEP_CLOCKWISE);
}

void Cubelet::rotateYClockwise()
{
    position = position.rotateY(ONE_STEP_CLOCKWISE);
}

void Cubelet::rotateZClockwise()
{
    position = position.rotateZ(ONE_STEP_CLOCKWISE);
}
