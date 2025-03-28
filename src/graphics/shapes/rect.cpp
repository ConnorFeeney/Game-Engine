#include <shapes/rect.h>

namespace cf {
    Rect::Rect(Vector2f position, Vector2f size) {
        Vector3f pos(position, 0.0f); //Convert 2d pos to flat 3d

        float width = size.x;
        float height = size.y;

        //Construct Object Vertecies
        vertecies.assign({
            //Top Left | Top Right | Bottom Right | Bottom Left
            {pos}, 
            {pos.x + width, pos.y, pos.z}, 
            {pos.x + width, pos.y + height, pos.z},
            {pos.x, pos.y + height, pos.z}
        });

        //Store Indecies
        indecies.assign({0, 1, 2, 2, 3, 0});
    }

    std::vector<Vector3f>& Rect::getVertecies() {
        return vertecies;
    }

    std::vector<unsigned int>& Rect::getIndecies() {
        return indecies;
    }
}