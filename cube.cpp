#include "cube.h"

Cube::Cube(): cubelets{
    ColoredCubelet(1, 1, 1),
    ColoredCubelet(1, 1, 0),
    ColoredCubelet(1, 1, -1),
    ColoredCubelet(1, 0, 1),
    ColoredCubelet(1, 0, 0),
    ColoredCubelet(1, 0, -1),
    ColoredCubelet(1, -1, 1),
    ColoredCubelet(1, -1, 0),
    ColoredCubelet(1, -1, -1),

    ColoredCubelet(0, 1, 1),
    ColoredCubelet(0, 1, 0),
    ColoredCubelet(0, 1, -1),
    ColoredCubelet(0, 0, 1),
    // There is no ColoredCubelet(0, 0, 0)
    ColoredCubelet(0, 0, -1),
    ColoredCubelet(0, -1, 1),
    ColoredCubelet(0, -1, 0),
    ColoredCubelet(0, -1, -1),

    ColoredCubelet(-1, 1, 1),
    ColoredCubelet(-1, 1, 0),
    ColoredCubelet(-1, 1, -1),
    ColoredCubelet(-1, 0, 1),
    ColoredCubelet(-1, 0, 0),
    ColoredCubelet(-1, 0, -1),
    ColoredCubelet(-1, -1, 1),
    ColoredCubelet(-1, -1, 0),
    ColoredCubelet(-1, -1, -1),
}
{
}

Face Cube::getFront()
{
    std::array<std::array<Color, 3>, 3> frontFace{};
    for (const auto& cubelet : cubelets)
    {
        if (cubelet.position.x == 1) // Check if the cubelet is on the front face
        {
            frontFace[cubelet.position.y + 1][cubelet.position.z + 1] = cubelet.front;
        }
    }
    return {frontFace};
}

Face Cube::getBack()
{
    std::array<std::array<Color, 3>, 3> backFace{};
    for (const auto& cubelet : cubelets)
    {
        if (cubelet.position.x == -1)
        {
            backFace[cubelet.position.y + 1][cubelet.position.z + 1] = cubelet.back;
        }
    }
    return {backFace};
}

Face Cube::getLeft()
{
    std::array<std::array<Color, 3>, 3> leftFace{};
    for (const auto& cubelet : cubelets)
    {
        if (cubelet.position.y == 1)
        {
            leftFace[cubelet.position.x + 1][cubelet.position.z + 1] = cubelet.left;
        }
    }
    return {leftFace};
}

Face Cube::getRight()
{
    std::array<std::array<Color, 3>, 3> leftFace{};
    for (const auto& cubelet : cubelets)
    {
        if (cubelet.position.y == -1)
        {
            leftFace[cubelet.position.x + 1][cubelet.position.z + 1] = cubelet.right;
        }
    }
    return {leftFace};
}

Face Cube::getTop()
{
    std::array<std::array<Color, 3>, 3> leftFace{};
    for (const auto& cubelet : cubelets)
    {
        if (cubelet.position.z == 1)
        {
            leftFace[cubelet.position.x + 1][cubelet.position.y + 1] = cubelet.top;
        }
    }
    return {leftFace};
}

Face Cube::getBottom()
{
    std::array<std::array<Color, 3>, 3> leftFace{};
    for (const auto& cubelet : cubelets)
    {
        if (cubelet.position.z == -1)
        {
            leftFace[cubelet.position.x + 1][cubelet.position.y + 1] = cubelet.bottom;
        }
    }
    return {leftFace};
}
