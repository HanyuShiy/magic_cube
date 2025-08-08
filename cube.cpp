#include "cube.h"

#include <iostream>
#include <random>

#include "layer.h"

Cube::Cube() : cubelets{
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
        if (frontLayer.contains(cubelet))
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
        if (backLayer.contains(cubelet))
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
        if (leftLayer.contains(cubelet))
        {
            leftFace[cubelet.position.z + 1][cubelet.position.x + 1] = cubelet.getFaceOn(LEFT_ORIENTATED);
        }
    }
    return {leftFace};
}

Face Cube::getRight()
{
    std::array<std::array<Color, 3>, 3> rightFace{};
    for (const auto& cubelet : cubelets)
    {
        if (rightLayer.contains(cubelet))
        {
            rightFace[cubelet.position.x + 1][cubelet.position.z + 1] = cubelet.getFaceOn(RIGHT_ORIENTATED);
        }
    }
    return {rightFace};
}

Face Cube::getTop()
{
    std::array<std::array<Color, 3>, 3> topFace{};
    for (const auto& cubelet : cubelets)
    {
        if (topLayer.contains(cubelet))
        {
            topFace[cubelet.position.x + 1][cubelet.position.y + 1] = cubelet.getFaceOn(TOP_ORIENTATED);
        }
    }
    return {topFace};
}

Face Cube::getBottom()
{
    std::array<std::array<Color, 3>, 3> bottomFace{};
    for (const auto& cubelet : cubelets)
    {
        if (bottomLayer.contains(cubelet))
        {
            bottomFace[cubelet.position.x + 1][cubelet.position.y + 1] = cubelet.getFaceOn(BOTTOM_ORIENTATED);
        }
    }
    return {bottomFace};
}

Cube& Cube::rotateClockwise(const Layer& layer, const Angle& angle, const int steps)
{
    // Rotate the given layer clockwise around its axis.
    // "Clockwise" is only relative to the given angle.
    // If the given angle < 0 or > pi, the effect may be a counterclockwise rotation, depending on the magnitude.

    for (size_t i = 0; i < steps; ++i)
    {
        for (auto& cubelet : cubelets)
        {
            if (layer.contains(cubelet))
            {
                cubelet.rotateAround(layer.getAxis(), angle);
            }
        }
    }
    return *this;
}

Cube& Cube::rotateDegreeClockwise(const Layer& layer, const Angle& angle)
{
    for (auto& cubelet : cubelets)
    {
        if (layer.contains(cubelet))
        {
            cubelet.rotateAround(layer.getAxis(), angle);
        }
    }

    return *this;
}

Cube& Cube::scramble(const int steps)
{
    const std::array layers{
        frontLayer, backLayer, topLayer, bottomLayer, rightLayer, leftLayer, x0Layer, y0Layer, z0Layer
    };
    const std::array angles{
        CLOCKWISE_90, COUNTERCLOCKWISE_90, HALF_ROUND
    };
    std::uniform_int_distribution dist1(0, 8);
    std::uniform_int_distribution dist2(0, 2);
    std::default_random_engine e(time(nullptr));
    for (size_t i = 0; i < steps; ++i)
    {
        this->rotateClockwise(layers[dist1(e)], angles[dist2(e)], 1);
    }
    return *this;
}
