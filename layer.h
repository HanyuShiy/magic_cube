#include <functional>

#include "colored_cubelet.h"

class Layer
{
public:
    std::function<bool(const ColoredCubelet& cubelet)> contains;
    explicit Layer(const std::function<bool(const ColoredCubelet& cubelet)>& contains);
};

const Layer frontLayer([](const ColoredCubelet& cubelet)-> bool { return cubelet.position.x == 1; });
const Layer backaLyer([](const ColoredCubelet& cubelet)-> bool { return cubelet.position.x == -1; });
const Layer rightLayer([](const ColoredCubelet& cubelet)-> bool { return cubelet.position.y == 1; });
const Layer leftLayer([](const ColoredCubelet& cubelet)-> bool { return cubelet.position.y == -1; });
const Layer topLayer([](const ColoredCubelet& cubelet)-> bool { return cubelet.position.z == 1; });
const Layer bottomLayer([](const ColoredCubelet& cubelet)-> bool { return cubelet.position.z == -1; });
