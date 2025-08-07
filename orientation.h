#pragma once

#include "angle.h"

class Orientation
{
    int x, y, z;

public:
    Orientation(int x, int y, int z);

    [[nodiscard]] Orientation rotateX(const Angle& angle) const;
    [[nodiscard]] Orientation rotateY(const Angle& angle) const;
    [[nodiscard]] Orientation rotateZ(const Angle& angle) const;

    bool operator==(const Orientation& that) const = default;
};

const auto FRONT_ORIENTATED = Orientation{1, 0, 0};
const auto BACK_ORIENTATED = Orientation{-1, 0, 0};
const auto TOP_ORIENTATED = Orientation{0, 0, 1};
const auto BOTTOM_ORIENTATED = Orientation{0, 0, -1};
const auto LEFT_ORIENTATED = Orientation{0, -1, 0};
const auto RIGHT_ORIENTATED = Orientation{0, 1, 0};
