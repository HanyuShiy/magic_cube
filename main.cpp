#include <iostream>
#include "cube.h"

int main()
{
    auto cube = Cube();
    // const auto bottom = cube.getBottom();
    // std::cout << "bottom face before rotation:\n";
    // bottom.print();

    cube.scramble(15);
    cube.resetZ0Layer(FRONT_ORIENTATED).resetZ1Layer();


    std::cout << "bottom face after rotation:\n";
    cube.getBottom().print();
    std::cout << "top face after rotation:\n";
    cube.getTop().print();
    std::cout << "left face after rotation:\n";
    cube.getLeft().print();
    std::cout << "right face after rotation:\n";
    cube.getRight().print();
    std::cout << "back face after rotation:\n";
    cube.getBack().print();
    std::cout << "front face after rotation:\n";
    cube.getFront().print();

    return 0;
}
