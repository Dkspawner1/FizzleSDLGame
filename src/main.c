#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include "game.h"

int main(int argc, char *argv[])
{

    Game *game = Create();
    if (game == NULL)
        return EXIT_FAILURE;

    if (!game->init(game))
    {
        Destroy(game);
        return EXIT_FAILURE;
    }

    while (game->isRunning(game))
    {
        game->handleEvents(game);
        game->update(game);
        game->render(game);
    }

    game->clean(game);
    Destroy(game);
    return EXIT_SUCCESS;
}