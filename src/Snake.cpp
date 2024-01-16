#include "Snake.hpp"
#include "Direction.hpp"

void Snake::init()
{
    idle = true;
    xPos = 240;
    yPos = 240;
}

void Snake::setDirection(Direction newDirection)
{
    idle = false;
    direction = newDirection;
}

void Snake::update()
{
    if (idle) {
        return;
    }

    switch (direction) {
        case up:
            yPos -= 5;
            break;
        case down:
            yPos += 5;
            break;
        case right:
            xPos += 5;
            break;
        case left:
            xPos -= 5;
            break;
    }

}

void Snake::render(SDL_Renderer *renderer) {
    SDL_Rect rect;
    rect.x = xPos;
    rect.y = yPos;
    rect.w = 10;
    rect.h = 10;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
}