#include "face.h"

class Cube
{
public:
    ColoredCubelet cubelets[26];

    Cube();

    void coloring();

    Face getFront();
    Face getBack();
    Face getLeft();
    Face getRight();
    Face getTop();
    Face getBottom();

    void rotateFrontClockwise();
    void rotateBackClockwise();
    void rotateTopClockwise();
    void rotateBottomClockwise();
    void rotateLeftClockwise();
    void rotateRightClockwise();

    void rotateClockwise(Orientation face_orientation, int steps);
    //void rotateClockwise(Orientation face_orientation, Angle angle);
};
