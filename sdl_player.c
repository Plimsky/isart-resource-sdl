//
// Created by v_nicopolsky on 18/09/17.
//

#include "sdl_player.h"
#include "sdl_image.h"

bool initPlayer(t_sdl_base *sdlBase, t_sdl_player *player)
{
    bool isSucceed = true;

    loadImage(&player->sprite, "player.png");

    if (player->sprite == NULL)
        isSucceed = false;

    player->texture = loadTexture(sdlBase, player->sprite);

    if (player->texture == NULL)
        isSucceed = false;

    return isSucceed;
}

void destroyPlayer(t_sdl_player *player)
{
    SDL_FreeSurface(player->sprite);
    SDL_DestroyTexture(player->texture);
}

void movePlayer(const Uint8 *keyboardState, t_sdl_player *player)
{
    int8_t playerX = 0;
    int8_t playerY = 0;
    int temp = 0;

    /* User Keyboard  */
    if(keyboardState[SDL_SCANCODE_LEFT] || keyboardState[SDL_SCANCODE_A])
    {
        playerX--;
    }

    if(keyboardState[SDL_SCANCODE_RIGHT] || keyboardState[SDL_SCANCODE_D])
    {
        playerX++;
    }

    if(keyboardState[SDL_SCANCODE_UP] || keyboardState[SDL_SCANCODE_W])
    {
        playerY--;
    }

    if(keyboardState[SDL_SCANCODE_DOWN] || keyboardState[SDL_SCANCODE_S])
    {
        playerY++;
    }

    player->rect.x += playerX;
    player->rect.y += playerY;
}