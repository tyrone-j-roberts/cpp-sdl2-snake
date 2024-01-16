#ifndef SNAKE_HPP
#define SNAKE_HPP
#include <SDL2/SDL.h>
#include "Direction.hpp"

class Snake {
    private:
        Direction direction;
        int xPos;
        int yPos;
        bool idle;
    public:
        void init();
        void setDirection(Direction newDirection);
        void update();
        void render(SDL_Renderer* renderer);
};

#endif