#include <graphics.h>

int main() {
    cf::Window window("Test", 1280, 720);

    while(!window.shouldClose()){
        window.render();
    }
}