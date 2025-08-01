#pragma once

#include <array>
#include <iostream>
#include "colored_cubelet.h"

class Face
{
public:
    std::array<std::array<Color, 3>, 3> colors;

    Face(const std::array<std::array<Color, 3>, 3>& colors);

    void print() const
    {
        for (auto line : colors)
        {
            for (auto color : line)
            {
                std::cout << static_cast<char>(color) << ' ';
            }
            std::cout << '\n';
        }
    }

};
