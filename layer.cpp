#include "layer.h"

Layer::Layer(const std::function<bool(const ColoredCubelet& cubelet)>& contains) : contains(contains)
{
}

