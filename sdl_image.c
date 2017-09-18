//
// Created by v_nicopolsky on 18/09/17.
//

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "sdl_image.h"

bool loadImage(SDL_Surface **surface, char *path)
{
    bool isSucceed = true;

    *surface = IMG_Load(path);
    if (*surface == NULL)
    {
        SDL_Log("Unable to load image %s! SDL Error: %s\n", path, SDL_GetError());
        isSucceed = false;
    }

    return isSucceed;
}

SDL_Texture *loadTexture(t_sdl_base *sdlBase, SDL_Surface *surface)
{
    SDL_Texture *texture = NULL;

    if (sdlBase == NULL || surface == NULL)
        return NULL;

    texture = SDL_CreateTextureFromSurface(sdlBase->renderer, surface);

    if (texture == NULL)
    {
        SDL_Log("Unable to load texture froam surface : %s\n", SDL_GetError());
        return NULL;
    }

    return texture;
}