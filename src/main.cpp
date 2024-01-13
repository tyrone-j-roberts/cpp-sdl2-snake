#include <iostream>
#include <SDL2/SDL.h>
#include <chrono>
#include <thread>

int main(int argc, char *argv[]) {

    SDL_Window* window = nullptr;
    SDL_Surface* screenSurface = nullptr;
    SDL_Renderer* renderer = nullptr;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        std::cout << "SDL could not be initialise. SDL Error: " << SDL_GetError() << std::endl; 
        return 0;
    }


    window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 500, 500, SDL_WINDOW_OPENGL);

    if (!window) {
        std::cout << "Window could not be created. SDL Error: " << SDL_GetError() << std::endl; 
        return 0;
    }

    SDL_ShowWindow(window);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_RenderClear(renderer);

    SDL_Rect rect;

    rect.x = 0;
    rect.y = 0;
    rect.w = 32;
    rect.h = 32;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    // stat = SDL_RenderDrawRect(renderer, &rect);

    // if (stat != 0) {
    //     std::cout << "Failed to draw rect. SDL Error: " << SDL_GetError() << std::endl; 
    // } 

    SDL_Event e; 
    
    while(true){ 

        SDL_PollEvent( &e );
        
        if( e.type == SDL_QUIT ) {
            break;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        SDL_RenderClear(renderer);

        rect.x++;

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        int stat = SDL_RenderFillRect(renderer, &rect);

        if (stat != 0) {
            std::cout << "Failed to fill rect. SDL Error: " << SDL_GetError() << std::endl; 
            break;
        } 

        SDL_RenderPresent(renderer);

        // SDL_Delay(3000);

    };

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}