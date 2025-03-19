#pragma once

#include <cfmath.h>
#include <vector>

#include "renderTarget.h"

namespace cf {
    class Drawable {
    public:
        std::vector<Vector2f>* getVertecies();
        std::vector<int>* getIndecies();

        void test(){
            Matrix balls(5, 5, 4);

            balls[0][3] = 2;
        }
    protected:
        std::vector<Vector2f> vertecies;
        std::vector<int> indecies;
    };
}