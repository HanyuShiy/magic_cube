#include "cube.h"

#include "layer.h"

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
    ColoredCubelet(-1, -1, -1)
}
{
    coloring();
}

void Cube::coloring()
{
    for (auto& cubelet : cubelets)
    {
        if (frontLayer.contains(cubelet))
        {
            cubelet.coloring(FRONT_ORIENTATED, Color::RED);
        }
        if (backLayer.contains(cubelet))
        {
            cubelet.coloring(BACK_ORIENTATED, Color::ORANGE);
        }
        if (topLayer.contains(cubelet))
        {
            cubelet.coloring(TOP_ORIENTATED, Color::WHITE);
        }
        if (bottomLayer.contains(cubelet))
        {
            cubelet.coloring(BOTTOM_ORIENTATED, Color::YELLOW);
        }
        if (leftLayer.contains(cubelet))
        {
            cubelet.coloring(LEFT_ORIENTATED, Color::BLUE);
        }
        if (rightLayer.contains(cubelet))
        {
            cubelet.coloring(RIGHT_ORIENTATED, Color::GREEN);
        }
    }
}

Face Cube::getFront()
{
    std::array<std::array<Color, 3>, 3> frontFace{};
    for (const auto& cubelet : cubelets)
    {
        if (xP1Layer.contains(cubelet))
        {
            frontFace[cubelet.position.y + 1][cubelet.position.z + 1] = cubelet.getFaceOn(FRONT_ORIENTATED);
        }
    }
    return {frontFace};
}

Face Cube::getBack()
{
    std::array<std::array<Color, 3>, 3> backFace{};
    for (const auto& cubelet : cubelets)
    {
        if (xN1Layer.contains(cubelet))
        {
            backFace[cubelet.position.y + 1][cubelet.position.z + 1] = cubelet.getFaceOn(BACK_ORIENTATED);
        }
    }
    return {backFace};
}

Face Cube::getLeft()
{
    std::array<std::array<Color, 3>, 3> leftFace{};
    for (const auto& cubelet : cubelets)
    {
        if (yN1Layer.contains(cubelet))
        {
            leftFace[cubelet.position.z + 1][cubelet.position.x + 1] = cubelet.getFaceOn(LEFT_ORIENTATED);
        }
    }
    return {leftFace};
}

Face Cube::getRight()
{
    std::array<std::array<Color, 3>, 3> leftFace{};
    for (const auto& cubelet : cubelets)
    {
        if (yP1Layer.contains(cubelet))
        {
            leftFace[cubelet.position.x + 1][cubelet.position.z + 1] = cubelet.getFaceOn(RIGHT_ORIENTATED);
        }
    }
    return {leftFace};
}

Face Cube::getTop()
{
    std::array<std::array<Color, 3>, 3> leftFace{};
    for (const auto& cubelet : cubelets)
    {
        if (zP1Layer.contains(cubelet))
        {
            leftFace[cubelet.position.x + 1][cubelet.position.y + 1] = cubelet.getFaceOn(TOP_ORIENTATED);
        }
    }
    return {leftFace};
}

Face Cube::getBottom()
{
    std::array<std::array<Color, 3>, 3> leftFace{};
    for (const auto& cubelet : cubelets)
    {
        if (zN1Layer.contains(cubelet))
        {
            leftFace[cubelet.position.x + 1][cubelet.position.y + 1] = cubelet.getFaceOn(BOTTOM_ORIENTATED);
        }
    }
    return {leftFace};
}

void Cube::rotateFrontClockwise()
{
    for (auto& cubelet : cubelets)
    {
        if (xP1Layer.contains(cubelet)) // cubelet.position.x=1
        {
            cubelet.rotateXClockwise(); // rotate cubelet.position
        }
    }
}

void Cube::rotateBackClockwise()
{
    for (auto& cubelet : cubelets)
    {
        if (xN1Layer.contains(cubelet)) // cubelet.position.x=1
        {
            cubelet.rotateXClockwise(); // rotate cubelet.position
        }
    }
}

void Cube::rotateTopClockwise()
{
    for (auto& cubelet : cubelets)
    {
        if (zP1Layer.contains(cubelet)) // cubelet.position.x=1
        {
            cubelet.rotateZClockwise(); // rotate cubelet.position
        }
    }
}

void Cube::rotateBottomClockwise()
{
    for (auto& cubelet : cubelets)
    {
        if (zN1Layer.contains(cubelet)) // cubelet.position.x=1
        {
            cubelet.rotateZClockwise(); // rotate cubelet.position
        }
    }
}

void Cube::rotateLeftClockwise()
{
    for (auto& cubelet : cubelets)
    {
        if (yN1Layer.contains(cubelet)) // cubelet.position.x=1
        {
            cubelet.rotateYClockwise(); // rotate cubelet.position
        }
    }
}

void Cube::rotateRightClockwise()
{
    for (auto& cubelet : cubelets)
    {
        if (yP1Layer.contains(cubelet)) // cubelet.position.x=1
        {
            cubelet.rotateYClockwise(); // rotate cubelet.position
        }
    }
}

void Cube::rotateClockwise(const Layer& layer, const int steps)
{
    for (size_t i = 0; i < steps; ++i)
    {
        for (auto& cubelet : cubelets)
        {
            if (layer.contains(cubelet))
            {
                cubelet.rotateAround(layer.getAxis());
            }
        }
    }
}
