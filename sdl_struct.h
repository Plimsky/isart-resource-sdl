//
// Created by v_nicopolsky on 18/09/17.
//

#ifndef SANDBOX_RUSH_04_SDL_STRUCT_H
#define SANDBOX_RUSH_04_SDL_STRUCT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct s_sdl_base
{
    SDL_Window *window;
    SDL_Renderer *renderer;
} t_sdl_base;

typedef struct s_sdl_player
{
    SDL_Surface *sprite;
    SDL_Texture *texture;
    SDL_Rect rect;
} t_sdl_player;

typedef struct s_game
{
    t_sdl_player player;
    t_sdl_base sdlBase;
    int score;
    int exit;
    const Uint8 *keyboardState;
} t_game;

#endif //SANDBOX_RUSH_04_SDL_STRUCT_H
