#pragma once

#include <functional>

#include "colored_cubelet.h"

class Layer
{
public:
    std::function<bool(const ColoredCubelet& cubelet)> contains;
    explicit Layer(const std::function<bool(const ColoredCubelet& cubelet)>& contains,
                   const Orientation& axisVec);

    [[nodiscard]] Orientation getAxis() const;

private:
    Orientation axis;
};

extern const Layer frontLayer;
extern const Layer backLayer;
extern const Layer rightLayer;
extern const Layer leftLayer;
extern const Layer topLayer;
extern const Layer bottomLayer;
extern const Layer x0Layer;
extern const Layer y0Layer;
extern const Layer z0Layer;
