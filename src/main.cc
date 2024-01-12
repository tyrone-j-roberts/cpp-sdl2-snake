#include <iostream>
#include <SDL2/SDL.h>
#include <chrono>
#include <thread>

int main(int argc, char *argv[]) {

    SDL_Window* window = nullptr;
    SDL_Surface* screenSurface = nullptr;

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
    
    SDL_Event e; 
    
    bool quit = false; 
    
    while( quit == false ){ 
        while( SDL_PollEvent( &e ) ){ 
            if( e.type == SDL_QUIT ) quit = true; 
        } 
    };

    return 0;
}