//
// Created by v_nicopolsky on 18/09/17.
//

#include "sdl_display.h"

void updateWindow(t_sdl_base *sdlBase)
{
    SDL_RenderPresent(sdlBase->renderer);
}

void clearScreen(t_sdl_base *sdlBase)
{
    if (SDL_RenderClear(sdlBase->renderer))
    {
        SDL_Log("Unable to clear screen renderer : %s\n", SDL_GetError());
    }
}