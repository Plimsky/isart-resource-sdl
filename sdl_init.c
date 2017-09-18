//
// Created by v_nicopolsky on 18/09/17.
//

#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "sdl_init.h"

bool initAllSDL(t_sdl_base *sdlBase)
{
    bool isSucceed;

    isSucceed = initSDL();

    if (isSucceed)
        isSucceed = initSDLImg();

    if (isSucceed)
        isSucceed = initSDLMainWindow(sdlBase);

    return isSucceed;
}

bool initSDL()
{
    bool isSucceed = true;

    if (SDL_Init(SDL_INIT_VALUES) != 0)
    {
        SDL_Log("Unable to initialize SDL: %s\n", SDL_GetError());
        isSucceed = false;
    }

    return isSucceed;
}

bool initSDLImg()
{
    bool isSucceed = true;
    int imgAfterInitResult = IMG_Init(SDL_INIT_IMG);

    if ((SDL_INIT_IMG & imgAfterInitResult) != SDL_INIT_IMG)
    {
        SDL_Log("IMG_Init: Failed to init required jpg and png support!\n");
        SDL_Log("IMG_Init: %s\n", IMG_GetError());
        isSucceed = false;
    }

    return isSucceed;
}

bool initSDLMainWindow(t_sdl_base *sdlBase)
{
    bool isSucceed;

    sdlBase->window = SDL_CreateWindow("My awesome2 SDL Window",
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       WINDOW_X_SIZE, WINDOW_Y_SIZE, 0);

    if (sdlBase->window == NULL)
    {
        SDL_Log("Unable to initialize Window: %s\n", SDL_GetError());
        isSucceed = false;
    }
    else
        isSucceed = initSDLRenderer(sdlBase);


    return isSucceed;
}

bool initSDLRenderer(t_sdl_base *sdlBase)
{
    bool isSucceed = true;

    sdlBase->renderer = SDL_CreateRenderer(sdlBase->window, -1, SDL_RENDERER_ACCELERATED);

    if (sdlBase->renderer == NULL)
    {
        SDL_Log("Unable to initialize Renderer: %s\n", SDL_GetError());
        isSucceed = false;
    }

    return isSucceed;
}