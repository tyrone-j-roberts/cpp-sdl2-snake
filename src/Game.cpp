#include "Game.hpp"

Game::Game() {}
Game::~Game() {}

bool Game::init(const char *title, int x, int y, int w, int h) 
{
    
    std::cout << "Initialising Game..." << std::endl;
    
    if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
    {
        std::cout << "SDL could not be initialise. SDL Error: " << SDL_GetError() << std::endl; 
        return false;
    }

    window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 500, 500, SDL_WINDOW_OPENGL);

    if (!window) {
        std::cout << "Window could not be created. SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    SDL_ShowWindow(window);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    running = true;

    return true;
}

bool Game::isRunning() 
{
    return running;
}

void Game::update()
{

}

void Game::handleEvents() 
{
    SDL_Event e; 

    SDL_PollEvent( &e );
        
    if( e.type == SDL_QUIT ) {
        running = false;
    }
}

void Game::render() 
{
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}