#include "Game.hpp"
#include "Snake.hpp"
#include "Direction.hpp"

Game::Game() {}
Game::~Game() {}

bool Game::init(const char *title, int x, int y, int w, int h) 
{
    
    std::cout << "Starting Game..." << std::endl;
    
    if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
    {
        std::cout << "SDL could not be initialise. SDL Error: " << SDL_GetError() << std::endl; 
        return false;
    }

    width = w;
    height = h;

    window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);

    if (!window) {
        std::cout << "Window could not be created. SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    SDL_ShowWindow(window);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    running = true;

    snake.init();

    return true;
}

bool Game::isRunning() 
{
    return running;
}

void Game::update()
{
    snake.update();
}

void Game::handleEvents() 
{
    SDL_Event e; 

    SDL_PollEvent( &e );

    switch(e.type) {
        case SDL_QUIT:
            running = false;
            return;
        case SDL_KEYDOWN:
            switch(e.key.keysym.sym) {
                case SDLK_w:
                case SDLK_UP:
                    snake.setDirection(up);
                    break;
                case SDLK_a:
                case SDLK_LEFT:
                    snake.setDirection(left);
                    break;
                case SDLK_s:
                case SDLK_DOWN:
                    snake.setDirection(down);
                    break;
                case SDLK_d:
                case SDLK_RIGHT:
                    snake.setDirection(right);
                    break;
            }
            return;
    }
        
    if( e.type == SDL_QUIT ) {
        running = false;
    }
}

void Game::render() 
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    snake.render(renderer);
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}