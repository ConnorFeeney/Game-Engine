#pragma once

#include <cfmath.h>
#include <vector>

namespace cf {
    class Drawable {
    public:
        virtual std::vector<Vector3f>& getVertecies() = 0;
        virtual std::vector<unsigned int>& getIndecies() = 0;

        virtual void setScale() = 0;
        virtual void setPosition() = 0;
        virtual void translate() = 0;
        virtual void rotate() = 0;
        
    protected:
        std::vector<Vector3f> vertecies;
        std::vector<unsigned int> indecies;
    };
}