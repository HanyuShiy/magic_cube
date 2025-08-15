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

