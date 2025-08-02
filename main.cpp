#include <iostream>
#include "cube.h"

int main()
{
    auto cube = Cube();
    auto bottom = cube.getBottom();
    std::cout << "bottom face before:\n";
    bottom.print();
    // cube.rotateFrontClockwise();
    // std::cout << "bottom face after:\n";
    // cube.getBottom().print();

    return 0;
}
