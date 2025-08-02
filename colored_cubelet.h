#pragma once

#include <array>
#include <vector>

#include "color.h"
#include "cubelet.h"

class CubeletFace
{
    Color color;

    Orientation orientation;

public:
    CubeletFace(const Orientation& orientation)
        : color(Color::EMPTY),
          orientation(orientation)
    {
    }

    void coloring(const Color color)
    {
        this->color = color;
    }
};

class ColoredCubelet : public Cubelet
{
public:
    // CubeletFace faces[6];
    std::array<CubeletFace, 6> faces;

    ColoredCubelet(int x, int y, int z);

    Color coloringCubelet(std::vector<bool> on_surfaces);

    void rotateColorXClockwise();
};
