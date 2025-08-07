#pragma once

class Angle
{
    static int normalize(int angle);

public:
    int value; // Unit pi/2

    explicit Angle(int value);

    [[nodiscard]] Angle add(Angle other) const;

    static int cos(Angle angle);
    static int sin(Angle angle);
};

const auto ANGLE_ZERO = Angle{0};
const auto HALF_ROUND = Angle{2};
const auto ONE_STEP_CLOCKWISE = Angle{1};
const auto ONE_STEP_COUNTERCLOCKWISE = Angle{-1};
