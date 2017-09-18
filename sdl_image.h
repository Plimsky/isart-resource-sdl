//
// Created by v_nicopolsky on 18/09/17.
//

#ifndef SANDBOX_RUSH_04_SDL_IMAGE_H
#define SANDBOX_RUSH_04_SDL_IMAGE_H

#include <stdbool.h>
#include "sdl_struct.h"

bool loadImage(SDL_Surface **surface, char *path);
SDL_Texture *loadTexture(t_sdl_base *sdlBase, SDL_Surface *surface);

#endif //SANDBOX_RUSH_04_SDL_IMAGE_H
