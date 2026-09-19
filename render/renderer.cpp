#include "renderer.hpp"
#include <SDL2/SDL.h>
#include <iostream>

SDL_Window* render::window = nullptr;
SDL_Renderer* render::renderer = nullptr;

bool render::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Ошибка инициализации: " << SDL_GetError() << std::endl;
        return false;
    }

    render::window = SDL_CreateWindow(
        "3D Test",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        render::width, render::height,
        SDL_WINDOW_SHOWN
    );
        if (!render::window) {
            std::cout << "Не удалось создать окно: " << SDL_GetError() << std::endl;
            SDL_Quit();
            return 1;
        }

    render::renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (!render::renderer) {
            std::cout << "Не удалось создать рендерер: " << SDL_GetError() << std::endl;
            SDL_DestroyWindow(render::window);
            SDL_Quit();
            return 1;
        }
    return true;
}
void render::clean(){
    if(render::renderer) SDL_DestroyRenderer(render::renderer);
    if(render::window) SDL_DestroyWindow(render::window);
    SDL_Quit();
}