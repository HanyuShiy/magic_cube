#include <iostream>
#include "cube.h"

int main()
{
    auto cube = Cube();

    auto front = cube.getFront();
    std::cout << "Front face of the cube:\n";
    front.print();
    std::cout << "Bottom face of the cube:\n";
    cube.getBottom().print();


    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}
