#pragma once

#include <cfmath.h>
#include <vector>

#include <rendering/renderTarget.h>

namespace cf {
    class Drawable {
    public:
        virtual std::vector<Vector2f>* getVertecies();
        virtual std::vector<int>* getIndecies();
    protected:
        std::vector<Vector2f> vertecies;
        std::vector<int> indecies;
    };
}