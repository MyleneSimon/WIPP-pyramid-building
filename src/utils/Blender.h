//
// Created by gerardin on 3/11/19.
//

#ifndef PYRAMIDBUILDING_BLENDER_H
#define PYRAMIDBUILDING_BLENDER_H

#include <cstddef>
#include "../api/Datatype.h"

template <class T>
class Blender {

private:
    BlendingMethod blendingMethod;

public:
    Blender(BlendingMethod blendingMethod) : blendingMethod(blendingMethod) {}

    void blend(T* tile, size_t index, T val){
        switch(blendingMethod) {
            case BlendingMethod::MAX:
                if (val > tile[index]) {
                    tile[index] = val;
                }
                break;
            case BlendingMethod::OVERLAY:
            default:
                tile[index] = val;
                break;
        }
    }

};

#endif //PYRAMIDBUILDING_BLENDER_H
