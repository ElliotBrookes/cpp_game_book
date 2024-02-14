#include "game.h"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>

Game::Game()
    :mWindow(nullptr)
    ,mIsRunning(true) {
    
};

bool Game::Initialize()
{
	// Initialize SDL
	int sdlResult = SDL_Init(SDL_INIT_VIDEO);
	if (sdlResult != 0)
	{
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return false;
	}
	
	// Create an SDL Window
	mWindow = SDL_CreateWindow(
		"Game Programming in C++ (Chapter 1)", // Window title
		100,	// Top left x-coordinate of window
		100,	// Top left y-coordinate of window
		1024,	// Width of window
		768,	// Height of window
		0		// Flags (0 for no flags set)
	);

	if (!mWindow)
	{
		SDL_Log("Failed to create window: %s", SDL_GetError());
		return false;
	}

    mRenderer = SDL_CreateRenderer(
            mWindow,
            -1,
            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );
    
    if (!mRenderer) {
        SDL_Log("Failed to create Renderer: %s", SDL_GetError());
        return false;
    }

    // Paddle starting position
    mPaddlePos.x = 10.0f;
    mPaddlePos.y = 768.0f/2.0f;

    // Ball starting position
    mBallPos.x = 1024.0f/2.0f;
    mBallPos.y = 768.0f/2.0f;

    return true;
};

void Game::RunLoop()
{
	while (mIsRunning)
	{
		ProcessInput();
		UpdateGame();
		GenerateOutput();
	}
};

void Game::Shutdown()
{
	SDL_DestroyWindow(mWindow);
    SDL_DestroyRenderer(mRenderer);
	SDL_Quit();
};

void Game::ProcessInput(){
    SDL_Event event;
    // While there are still events in the queue
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                mIsRunning = false;
                break;
        }
    }

    const Uint8* state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_ESCAPE]) {
        mIsRunning = false;
    }
};

void Game::UpdateGame(){};

void Game::GenerateOutput(){
    // Prep drawing buffer
    SDL_SetRenderDrawColor(
            mRenderer,
            0,
            0,
            255,
            255
    );
    SDL_RenderClear(mRenderer);

    // Draw game scene/ graphics

    SDL_SetRenderDrawColor(
            mRenderer,
            255,
            255,
            255,
            255
    );
    const int thickness = 15;
    SDL_Rect wall {
        0,
        0,
        1024,
        thickness
    };

    SDL_Rect ball {
        static_cast<int> (mBallPos.x - thickness/2.0f),
        static_cast<int> (mBallPos.y - thickness/2.0f),
        thickness,
        thickness
    };

    SDL_Rect paddle {
        static_cast<int> (mPaddlePos.x - thickness/2.0f),
        static_cast<int> (mPaddlePos.y - thickness*4),
        thickness,
        thickness * 8
    };


    SDL_RenderFillRect(mRenderer, &wall);
    SDL_RenderFillRect(mRenderer, &ball);
    SDL_RenderFillRect(mRenderer, &paddle);







    // Swap the buffers
    SDL_RenderPresent(mRenderer);

};
