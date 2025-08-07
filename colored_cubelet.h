#pragma once

#include <array>

#include "cubelet.h"
#include "cubelet_face.h"


class ColoredCubelet final : public Cubelet
{
public:
    // CubeletFace faces[6];
    std::array<CubeletFace, 6> faces;

    ColoredCubelet(int x, int y, int z);

    void coloring(Orientation orientation, Color color);

    [[nodiscard]] Color getFaceOn(Orientation orientation) const;

    void rotateXClockwise() override;
    void rotateYClockwise() override;
    void rotateZClockwise() override;

    void rotateAround(Orientation axis);
};
