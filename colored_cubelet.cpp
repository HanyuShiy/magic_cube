#include "colored_cubelet.h"

ColoredCubelet::ColoredCubelet(const int x, const int y, const int z):
    Cubelet(x, y, z),
    front(EMPTY), back(EMPTY), left(EMPTY), right(EMPTY), top(EMPTY), bottom(EMPTY)
{
    if (onFrontFace())
    {
        front = RED;
    }
    if (onBackFace())
    {
        back = ORANGE;
    }
    if (onLeftFace())
    {
        left = GREEN;
    }
    if (onRightFace())
    {
        right = BLUE;
    }
    if (onTopFace())
    {
        top = WHITE;
    }
    if (onBottomFace())
    {
        bottom = YELLOW;
    }
}
