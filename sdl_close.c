//
// Created by v_nicopolsky on 18/09/17.
//

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "sdl_close.h"

void closeSDL(t_sdl_base *sdlBase)
{
    closeSDLBase(sdlBase);

    IMG_Quit();
    SDL_Quit();
}

void closeSDLBase(t_sdl_base *sdlBase)
{
    if (sdlBase == NULL)
        return;

    if (sdlBase->renderer != NULL)
    {
        SDL_DestroyRenderer(sdlBase->renderer);
        sdlBase->window = NULL;
    }

    if (sdlBase->window != NULL)
    {
        SDL_DestroyWindow(sdlBase->window);
        sdlBase->window = NULL;
    }
}