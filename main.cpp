#include <iostream>
#include "cube.h"

int main()
{
    auto cube = Cube();
    const auto bottom = cube.getBottom();
    std::cout << "bottom face before rotation:\n";
    bottom.print();

    cube.rotateFrontClockwise();
    std::cout << "bottom face after:\n";
    cube.getBottom().print();
    cube.getTop().print();
    cube.getLeft().print();
    cube.getRight().print();
    cube.getBack().print();
    cube.getFront().print();
    return 0;
}
