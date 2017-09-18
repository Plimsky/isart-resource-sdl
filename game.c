//
// Created by v_nicopolsky on 18/09/17.
//

#include "game.h"
#include "sdl_init.h"
#include "sdl_player.h"
#include "sdl_display.h"
#include "sdl_close.h"

int game()
{
    t_game game;

    if (!initAllSDL(&game.sdlBase))
        return EXIT_FAILURE;

    if (!initPlayer(&game.sdlBase, &game.player))
        return EXIT_FAILURE;

    game.exit = 0;
    game.keyboardState = SDL_GetKeyboardState(NULL);

    game.player.rect.h = 100;
    game.player.rect.w = 50;

    loopGame(game);

    destroyPlayer(&game.player);
    closeSDL(&game.sdlBase);

    return EXIT_SUCCESS;
}

void loopGame(t_game game)
{

    while (game.exit != 1)
    {
        checkInput(&game);

        SDL_PumpEvents();

        movePlayer(game.keyboardState, &game.player);

        SDL_RenderCopy(game.sdlBase.renderer, game.player.texture, NULL, &game.player.rect);

        updateWindow(&game.sdlBase);

        clearScreen(&game.sdlBase);
    }

}

void checkInput(t_game *game)
{
    SDL_Event event;

    while (SDL_PollEvent(&event) != 0)
    {
        if (event.type == SDL_QUIT)
        {
            game->exit = 1;
            break;
        }
        else if (event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
                case SDLK_ESCAPE:
                    game->exit = 1;
                    break;
                default:
                    break;
            }
        }
    }
}