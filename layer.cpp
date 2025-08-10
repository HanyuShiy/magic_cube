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



// bool Layer::sameColorOn(const std::vector<CubeletFace>& cubelet_faces)
// {
//     const Color first = cubelet_faces[0].color;
//     for (auto& face : cubelet_faces)
//     {
//         if (face.color != first)
//         {
//             return false;
//         }
//     }
//     return true;
// }
