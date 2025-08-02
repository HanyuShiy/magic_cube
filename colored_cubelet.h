#include <array>

#include "color.h"
#include "cubelet.h"
#include "orientation.h"

class CubeletFace
{
public:
    Color color;

    Orientation orientation;

    CubeletFace(const Orientation& orientation)
        : color(Color::EMPTY),
          orientation(orientation)
    {
    }

    void coloring(Color color);
};

class ColoredCubelet : public Cubelet
{
public:
    // CubeletFace faces[6];
    std::array<CubeletFace, 6> faces;

    ColoredCubelet(int x, int y, int z);

    void coloring(Orientation orientation, Color color);

    void rotateColorXClockwise();

    Color getFaceOn(Orientation orientation) const;
};
