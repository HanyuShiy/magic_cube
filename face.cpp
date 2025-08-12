#include "face.h"
#include <iostream>

Face::Face(const std::array<std::array<Color, 3>, 3>& colors): colors(colors)
{
}

Color Face::originColor() const
{
    return this->colors[1][1];
}

void Face::print() const
{
    for (auto& line : colors)
    {
        for (const auto& color : line)
        {
            std::cout << static_cast<char>(color) << ' ';
        }
        std::cout << '\n';
    }
}
