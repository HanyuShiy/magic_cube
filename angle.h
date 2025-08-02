#pragma once

class Angle
{
    static int normalize(int angle);

public:
    int value; // Unit pi/2

    bool operator==(Angle other);

    explicit Angle(int value);

    Angle add(const Angle other) const;

    static int cos(Angle const angle);

    static int sin(Angle const angle);
};

const auto ANGLE_ZERO = Angle{0};
const auto HALF_ROUND = Angle{2};
const auto ONE_STEP_CLOCKWISE = Angle{-1}; // -1 for clockwise rotation, -90 degrees
const auto ONE_STEP_COUNTERCLOCKWISE = Angle{1}; // 1 for counterclockwise rotation, +90 degrees
