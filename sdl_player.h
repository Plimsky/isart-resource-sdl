//
// Created by v_nicopolsky on 18/09/17.
//

#ifndef SANDBOX_RUSH_04_SDL_PLAYER_H
#define SANDBOX_RUSH_04_SDL_PLAYER_H

#include <stdbool.h>
#include "sdl_struct.h"

bool initPlayer(t_sdl_base *sdlBase, t_sdl_player *player);

void destroyPlayer(t_sdl_player *player);

void movePlayer(const Uint8 *keyboardState, t_sdl_player *player);

#endif //SANDBOX_RUSH_04_SDL_PLAYER_H
