#include <graphics.h>

int main() {
    cf::Window window("Test", 1280, 720, true);

    while(!window.shouldClose()){
        window.render();
    }
}