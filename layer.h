#include <functional>

#include "colored_cubelet.h"

class Layer
{
public:
    std::function<bool(const ColoredCubelet& cubelet)> contains;
    explicit Layer(const std::function<bool(const ColoredCubelet& cubelet)>& contains);
};

const Layer xP1Layer([](const ColoredCubelet& cubelet)-> bool { return cubelet.position.x == 1; });
const Layer xN1Layer([](const ColoredCubelet& cubelet)-> bool { return cubelet.position.x == -1; });
const Layer yP1Layer([](const ColoredCubelet& cubelet)-> bool { return cubelet.position.y == 1; });
const Layer yN1Layer([](const ColoredCubelet& cubelet)-> bool { return cubelet.position.y == -1; });
const Layer zP1Layer([](const ColoredCubelet& cubelet)-> bool { return cubelet.position.z == 1; });
const Layer zN1Layer([](const ColoredCubelet& cubelet)-> bool { return cubelet.position.z == -1; });
const Layer x0Layer([](const ColoredCubelet& cubelet)-> bool { return cubelet.position.x == 0; });
const Layer y0Layer([](const ColoredCubelet& cubelet)-> bool { return cubelet.position.y == 0; });
const Layer z0Layer([](const ColoredCubelet& cubelet)-> bool { return cubelet.position.z == 0; });
