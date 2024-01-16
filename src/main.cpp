#include <chrono>
#include <thread>

#include "Game.hpp"

int main(int argc, char *argv[]) {

    Game game;

    if (!game.init("Snake Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 500, 500)) {
        return 0;
    }

    while(game.isRunning()) {
        game.handleEvents();
        game.update();
        game.render();
        SDL_Delay(1000 / 15);
    }

    game.clean();

    return 0;
}