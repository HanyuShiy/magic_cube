#include "face.h"
#include "layer.h"

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

    void rotateClockwise(const Layer& layer, int steps = 1);
    //void rotateClockwise(Orientation face_orientation, Angle angle);
};
