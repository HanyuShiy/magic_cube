#include "layer.h"

Layer::Layer(const std::function<bool(const ColoredCubelet& cubelet)>& contains,
             const Orientation& axisVec)
    : contains(contains), axis(axisVec)
{
}

Orientation Layer::getAxis() const
{
    return axis;
}

const Layer frontLayer([](const ColoredCubelet& cubelet)-> bool { return cubelet.position.x == 1; }, {1, 0, 0});
const Layer backLayer([](const ColoredCubelet& cubelet)-> bool { return cubelet.position.x == -1; }, {1, 0, 0});
const Layer rightLayer([](const ColoredCubelet& cubelet)-> bool { return cubelet.position.y == 1; }, {0, 1, 0});
const Layer leftLayer([](const ColoredCubelet& cubelet)-> bool { return cubelet.position.y == -1; }, {0, 1, 0});
const Layer topLayer([](const ColoredCubelet& cubelet)-> bool { return cubelet.position.z == 1; }, {0, 0, 1});
const Layer bottomLayer([](const ColoredCubelet& cubelet)-> bool { return cubelet.position.z == -1; }, {0, 0, 1});
const Layer x0Layer([](const ColoredCubelet& cubelet)-> bool { return cubelet.position.x == 0; }, {1, 0, 0});
const Layer y0Layer([](const ColoredCubelet& cubelet)-> bool { return cubelet.position.y == 0; }, {0, 1, 0});
const Layer z0Layer([](const ColoredCubelet& cubelet)-> bool { return cubelet.position.z == 0; }, {0, 0, 1});
