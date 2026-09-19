#pragma once
#include <SDL2/SDL.h>

namespace render{
    inline const int width = 800, height = 800;
    extern SDL_Window* window;
    extern SDL_Renderer* renderer;

    bool init();
    void clean();
}