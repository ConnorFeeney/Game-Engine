#pragma once

namespace cf {
    typedef struct vector2f{
        float x;
        float y;

        vector2f(float x, float y);
    } vector2f;

    typedef struct vector3f{
        float x;
        float y;
        float z;

        vector3f(float x, float y, float z);
    } vector3f;
}