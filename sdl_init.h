//
// Created by v_nicopolsky on 18/09/17.
//

#ifndef SANDBOX_RUSH_04_SDL_INIT_H
#define SANDBOX_RUSH_04_SDL_INIT_H

#include <stdbool.h>
#include "sdl_struct.h"

#define SDL_INIT_VALUES SDL_INIT_EVERYTHING
#define SDL_INIT_IMG IMG_INIT_PNG

#define WINDOW_X_SIZE 640
#define WINDOW_Y_SIZE 480

bool initAllSDL(t_sdl_base *sdlBase);

bool initSDL();

bool initSDLImg();

bool initSDLMainWindow(t_sdl_base *sdlBase);

bool initSDLRenderer(t_sdl_base *sdlBase);

#endif //SANDBOX_RUSH_04_SDL_INIT_H
