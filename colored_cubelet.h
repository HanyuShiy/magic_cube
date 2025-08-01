#pragma once

#include "cubelet.h"

enum Color
{
    RED = 'R',
    GREEN = 'G',
    BLUE = 'B',
    YELLOW = 'Y',
    ORANGE = 'O',
    WHITE = 'W',
    EMPTY = ' '
};

class ColoredCubelet : public Cubelet
{
public:
    Color front, back, left, right, top, bottom;

    ColoredCubelet(int x, int y, int z);
};
