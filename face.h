#pragma once

#include <array>
#include "colored_cubelet.h"

class Face
{
public:
    std::array<std::array<Color, 3>, 3> colors;
    Face(const std::array<std::array<Color, 3>, 3>& colors);

    void print() const;
};
