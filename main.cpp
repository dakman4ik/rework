#include <SDL2/SDL.h>
#include <iostream>

int main(int argc, char* argv[]) {
    // Инициализируем SDL2
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Ошибка инициализации: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Создаем окно
    SDL_Window* window = SDL_CreateWindow(
        "SDL2 Linux Test",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        800, 600,
        SDL_WINDOW_SHOWN
    );

    if (!window) {
        std::cout << "Не удалось создать окно: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Создаем рендерер (он отвечает за отрисовку внутри окна)
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cout << "Не удалось создать рендерер: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    bool running = true;
    SDL_Event event;

    // Главный цикл программы
    while (running) {
        // Обязательно обрабатываем события ОС (это "оживляет" окно)
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false; // Нажали на крестик — выходим
            }
        }

        // Задаем цвет очистки экрана (Красный, Зеленый, Синий, Альфа) -> Белый
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer); // Очищаем экран этим цветом
        
        SDL_SetRenderDrawColor(renderer, 51, 23, 42, 255);
        SDL_RenderDrawPoint(renderer, 400,300);
        // Здесь в будущем будет отрисовка вашей игры/приложения
        SDL_RenderPresent(renderer); // Выводим всё, что нарисовали, на экран
        
        SDL_Delay(16); // Небольшая задержка (~60 FPS), чтобы не перегружать процессор
    }

    // Очистка ресурсов
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
