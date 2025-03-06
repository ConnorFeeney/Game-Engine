#include "../graphics/graphics.h"

int main(){
    cf::Window window("Window", 1280, 720);

    while(!window.shouldClose()){
        window.update();
    }

    return 0;
}