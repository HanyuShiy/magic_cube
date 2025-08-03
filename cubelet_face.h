#include "color.h"
#include "orientation.h"

class CubeletFace
{
public:
    Color color;

    Orientation orientation;

    CubeletFace(const Orientation& orientation);

    void coloring(Color color);

    void rotateXClockwise();
};
