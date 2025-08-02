#include "colored_cubelet.h"

ColoredCubelet::ColoredCubelet(const int x, const int y, const int z):
    Cubelet(x, y, z),
    faces{
        {
            CubeletFace(FRONT_ORIENTATED),
            CubeletFace(BACK_ORIENTATED),
            CubeletFace(TOP_ORIENTATED),
            CubeletFace(BOTTOM_ORIENTATED),
            CubeletFace(LEFT_ORIENTATED),
            CubeletFace(RIGHT_ORIENTATED)
        }
    }
{
}

Color ColoredCubelet::coloringCubelet(std::vector<bool> on_surfaces)
{
    if (on_surfaces)
    {
        // wip...
    }

}

void ColoredCubelet::rotateColorXClockwise()
{
    rotateXClockwise();
}


