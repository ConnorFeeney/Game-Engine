#pragma once

#include <rendering/drawable.h>

namespace cf {
    class Rect : public Drawable {
    public:
        Rect(Vector2f position, Vector2f size);
        ~Rect() = default;

        std::vector<Vector3f>& getVertecies();
        std::vector<unsigned int>& getIndecies();

        void setScale() {};
        void setPosition() {};
        void translate() {};
        void rotate() {};
    };
}