#include "position.h"

class Cubelet
{
public:
    Position position;

    Cubelet(const int x, const int y, const int z);

    void rotateXClockwise();
    void rotateYClockwise();
    void rotateZClockwise();

    bool onFrontFace() const;
    bool onBackFace() const;
    bool onLeftFace() const;
    bool onRightFace() const;
    bool onTopFace() const;
    bool onBottomFace() const;
};
