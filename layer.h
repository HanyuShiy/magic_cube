#pragma once

#include <functional>

#include "colored_cubelet.h"

class Layer
{
public:
    std::function<bool(const ColoredCubelet& cubelet)> contains;
    explicit Layer(const std::function<bool(const ColoredCubelet& cubelet)>& contains,
                   const Orientation& axisVec);

    Orientation getAxis() const;

private:
    Orientation axis;
};

const Layer xP1Layer([](const ColoredCubelet& cubelet)-> bool { return cubelet.position.x == 1; }, {1, 0, 0});
const Layer xN1Layer([](const ColoredCubelet& cubelet)-> bool { return cubelet.position.x == -1; }, {1, 0, 0});
const Layer yP1Layer([](const ColoredCubelet& cubelet)-> bool { return cubelet.position.y == 1; }, {0, 1, 0});
const Layer yN1Layer([](const ColoredCubelet& cubelet)-> bool { return cubelet.position.y == -1; }, {0, 1, 0});
const Layer zP1Layer([](const ColoredCubelet& cubelet)-> bool { return cubelet.position.z == 1; }, {0, 0, 1});
const Layer zN1Layer([](const ColoredCubelet& cubelet)-> bool { return cubelet.position.z == -1; }, {0, 0, 1});
const Layer x0Layer([](const ColoredCubelet& cubelet)-> bool { return cubelet.position.x == 0; }, {1, 0, 0});
const Layer y0Layer([](const ColoredCubelet& cubelet)-> bool { return cubelet.position.y == 0; }, {0, 1, 0});
const Layer z0Layer([](const ColoredCubelet& cubelet)-> bool { return cubelet.position.z == 0; }, {0, 0, 1});

inline const Layer& frontLayer = xP1Layer;
inline const Layer& backLayer = xN1Layer;
inline const Layer& rightLayer = yP1Layer;
inline const Layer& leftLayer = yN1Layer;
inline const Layer& topLayer = zP1Layer;
inline const Layer& bottomLayer = zN1Layer;
