#include "face.h"

class Cube
{
public:
    ColoredCubelet cubelets[26];
    // constructor to initialize 26 cubelets

    Cube();

    void coloring();

    Face getFront();
    Face getBack();
    Face getLeft();
    Face getRight();
    Face getTop();
    Face getBottom();

    void rotateFrontClockwise();

    // void rotateClockwise(Orientation face_orientation, Angle angle);

};
