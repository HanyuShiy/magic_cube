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

    void rotateXClockwise(Angle angle) override;
    void rotateYClockwise(Angle angle) override;
    void rotateZClockwise(Angle angle) override;
    void rotateAround(const Orientation& axis, const Angle& angle);

    bool isEdge() const;
    bool isCorner() const;

    ColoredCubelet* findColor(Color color);
};
