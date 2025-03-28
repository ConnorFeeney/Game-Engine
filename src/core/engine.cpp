#include <graphics.h>
#include <shapes/rect.h>

int main() {
    cf::Window window("Test", 1280, 720);
    cf::Rect r({20, 20}, {100, 100});

    while(!window.shouldClose()){
        window.draw(r);
        window.render();
    }
}