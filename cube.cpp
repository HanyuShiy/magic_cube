#include "cube.h"

#include <iostream>
#include <random>
#include <sstream>

#include "layer.h"
#include "rotation.h"

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
            cubelet.coloring(FRONT_ORIENTATED, RED);
        }
        if (backLayer.contains(cubelet))
        {
            cubelet.coloring(BACK_ORIENTATED, ORANGE);
        }
        if (topLayer.contains(cubelet))
        {
            cubelet.coloring(TOP_ORIENTATED, WHITE);
        }
        if (bottomLayer.contains(cubelet))
        {
            cubelet.coloring(BOTTOM_ORIENTATED, YELLOW);
        }
        if (leftLayer.contains(cubelet))
        {
            cubelet.coloring(LEFT_ORIENTATED, GREEN);
        }
        if (rightLayer.contains(cubelet))
        {
            cubelet.coloring(RIGHT_ORIENTATED, BLUE);
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
    return Face(frontFace);
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
    return Face(backFace);
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
    return Face(leftFace);
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
    return Face(rightFace);
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
    return Face(topFace);
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
    return Face(bottomFace);
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
        frontLayer, backLayer, topLayer, bottomLayer, rightLayer, leftLayer
        // , x0Layer, y0Layer, z0Layer
    };
    const std::array angles{
        CLOCKWISE_90, COUNTERCLOCKWISE_90, HALF_ROUND
    };
    std::uniform_int_distribution dist1(0, 5);
    std::uniform_int_distribution dist2(0, 2);
    std::default_random_engine e(time(nullptr));
    for (size_t i = 0; i < steps; ++i)
    {
        this->rotateClockwise(layers[dist1(e)], angles[dist2(e)]);
    }
    return *this;
}

Cube& Cube::applyAlgo(const std::string& rotations)
// Accepted rotations must be a sequence of basic rotations, each separated by spaces.
{
    std::istringstream iss(rotations);
    std::string token;
    while (iss >> token)
    {
        if (auto rot = Rotation.find(token); rot != Rotation.end())
        {
            rot->second(*this);
        }
    }
    return *this;
}

// Cube& Cube::solveWhiteCross() // wip: only white-edge pieces on the frontLayer have been solved
// {
//     for (auto& cubelet : cubelets)
//     {
//         if (frontLayer.contains(cubelet))
//         {
//             if (const auto* target = cubelet.findColor(WHITE))
//             {
//                 if (target->isCorner()) continue;
//                 if (target->isEdge())
//                 {
//                     CubeletFace white_face, another_face;
//                     for (const auto& face : target->faces)
//                     {
//                         if (face.color == WHITE)
//                         {
//                             white_face = face;
//                         }
//                         if (face.color != EMPTY && face.color != WHITE)
//                         {
//                             another_face = face;
//                         }
//                     }
//
//                     if (another_face.color == getFront().originColor() && !topLayer.contains(cubelet))
//                     {
//                         if (white_face.orientation == LEFT_ORIENTATED)
//                         {
//                             this->applyAlgo("F");
//                         }
//                         if (white_face.orientation == RIGHT_ORIENTATED)
//                         {
//                             this->applyAlgo("F'");
//                         }
//                         if (white_face.orientation == BOTTOM_ORIENTATED)
//                         {
//                             this->applyAlgo("F F");
//                         }
//                         if (white_face.orientation == FRONT_ORIENTATED)
//                         {
//                             if (another_face.orientation == LEFT_ORIENTATED)
//                             {
//                             }
//                             if (another_face.orientation == RIGHT_ORIENTATED)
//                             {
//                             }
//                             if (another_face.orientation == BOTTOM_ORIENTATED)
//                             {
//                                 applyAlgo("D R F' R'");
//                             }
//                         }
//                     }
//                     if (another_face.color == getLeft().originColor()) // leftLayer
//                     {
//                         if (white_face.orientation == LEFT_ORIENTATED)
//                         {
//                             this->applyAlgo("U' F U");
//                         }
//                         if (white_face.orientation == RIGHT_ORIENTATED)
//                         {
//                             this->applyAlgo("U' F' U");
//                         }
//                         if (white_face.orientation == BOTTOM_ORIENTATED)
//                         {
//                             this->applyAlgo("D' L L");
//                         }
//                         if (white_face.orientation == FRONT_ORIENTATED)
//                         {
//                             if (another_face.orientation == LEFT_ORIENTATED)
//                             {
//                                 applyAlgo("L'");
//                             }
//                             if (another_face.orientation == RIGHT_ORIENTATED)
//                             {
//                                 applyAlgo("U' U' R U U");
//                             }
//                             if (another_face.orientation == BOTTOM_ORIENTATED)
//                             {
//                                 applyAlgo("F L' F'");
//                             }
//                         }
//                     }
//                     if (another_face.color == getRight().originColor()) // rightLayer
//                     {
//                         if (white_face.orientation == LEFT_ORIENTATED)
//                         {
//                             this->applyAlgo("U F U'");
//                         }
//                         if (white_face.orientation == RIGHT_ORIENTATED)
//                         {
//                             this->applyAlgo("U F' U'");
//                         }
//                         if (white_face.orientation == BOTTOM_ORIENTATED)
//                         {
//                             this->applyAlgo("D R R");
//                         }
//                         if (white_face.orientation == FRONT_ORIENTATED)
//                         {
//                             if (another_face.orientation == LEFT_ORIENTATED)
//                             {
//                                 applyAlgo("U U L' U' U'");
//                             }
//                             if (another_face.orientation == RIGHT_ORIENTATED)
//                             {
//                                 applyAlgo("R");
//                             }
//                             if (another_face.orientation == BOTTOM_ORIENTATED)
//                             {
//                                 applyAlgo("F' R F");
//                             }
//                         }
//                     }
//                     if (another_face.color == getBack().originColor()) // backLayer
//                     {
//                         if (white_face.orientation == LEFT_ORIENTATED)
//                         {
//                             this->applyAlgo("U U F U U");
//                         }
//                         if (white_face.orientation == RIGHT_ORIENTATED)
//                         {
//                             this->applyAlgo("U U F' U U");
//                         }
//                         if (white_face.orientation == BOTTOM_ORIENTATED)
//                         {
//                             this->applyAlgo("D D F F");
//                         }
//                         if (white_face.orientation == FRONT_ORIENTATED)
//                         {
//                             if (another_face.orientation == LEFT_ORIENTATED)
//                             {
//                                 applyAlgo("U' L' U");
//                             }
//                             if (another_face.orientation == RIGHT_ORIENTATED)
//                             {
//                                 applyAlgo("U R U'");
//                             }
//                             if (another_face.orientation == BOTTOM_ORIENTATED)
//                             {
//                                 applyAlgo("D D B B");
//                             }
//                         }
//                     }
//                 }
//             }
//             else {continue;}
//         }
//     }
//     return *this;
// }
