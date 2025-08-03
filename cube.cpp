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
    ColoredCubelet(-1, -1, -1)
}
{
    coloring();
}

void Cube::coloring()
{
    for (auto& cubelet : cubelets)
    {
        if (cubelet.onFrontFace())
        {
            cubelet.coloring(FRONT_ORIENTATED, Color::RED);
        }
        if (cubelet.onBackFace())
        {
            cubelet.coloring(BACK_ORIENTATED, Color::ORANGE);
        }
        if (cubelet.onTopFace())
        {
            cubelet.coloring(TOP_ORIENTATED, Color::WHITE);
        }
        if (cubelet.onBottomFace())
        {
            cubelet.coloring(BOTTOM_ORIENTATED, Color::YELLOW);
        }
        if (cubelet.onLeftFace())
        {
            cubelet.coloring(LEFT_ORIENTATED, Color::BLUE);
        }
        if (cubelet.onRightFace())
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
        if (cubelet.onFrontFace()) // Check if the cubelet is on the front face
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
        if (cubelet.onBackFace())
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
        if (cubelet.onLeftFace())
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
        if (cubelet.onRightFace())
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
        if (cubelet.onTopFace())
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
        if (cubelet.onBottomFace())
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
        if (cubelet.onFrontFace()) // cubelet.position.x=1
        {
            cubelet.rotateXClockwise(); // rotate cubelet.position
        }
    }
}

void Cube::rotateBackClockwise()
{
    for (auto& cubelet : cubelets)
    {
        if (cubelet.onBackFace()) // cubelet.position.x=1
        {
            cubelet.rotateXClockwise(); // rotate cubelet.position
        }
    }
}

void Cube::rotateTopClockwise()
{
    for (auto& cubelet : cubelets)
    {
        if (cubelet.onTopFace()) // cubelet.position.x=1
        {
            cubelet.rotateZClockwise(); // rotate cubelet.position
        }
    }
}

void Cube::rotateBottomClockwise()
{
    for (auto& cubelet : cubelets)
    {
        if (cubelet.onBottomFace()) // cubelet.position.x=1
        {
            cubelet.rotateZClockwise(); // rotate cubelet.position
        }
    }
}

void Cube::rotateLeftClockwise()
{
    for (auto& cubelet : cubelets)
    {
        if (cubelet.onLeftFace()) // cubelet.position.x=1
        {
            cubelet.rotateYClockwise(); // rotate cubelet.position
        }
    }
}

void Cube::rotateRightClockwise()
{
    for (auto& cubelet : cubelets)
    {
        if (cubelet.onRightFace()) // cubelet.position.x=1
        {
            cubelet.rotateYClockwise(); // rotate cubelet.position
        }
    }
}

// void Cube::rotateClockwise(Orientation face_orientation, Angle angle)
// {
// }
