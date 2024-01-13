#ifndef GAME_HPP
#define GAME_HPP
#include <SDL2/SDL.h>
#include <iostream>

class Game {
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        bool running;
    
    public:
        Game();
        ~Game();
        bool init(const char *title, int x, int y, int w, int h);
        bool isRunning();
        void handleEvents();
        void update();
        void render();
        void clean();
    
};

#endif