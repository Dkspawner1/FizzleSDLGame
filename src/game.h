#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct Game Game;

struct Game
{
    bool (*init)(Game *self);
    void (*handleEvents)(Game *self);
    void (*update)(Game *self);
    void (*render)(Game *self);
    void (*clean)(Game *self);
    bool (*isRunning)(Game *self);
};

Game *Create();
void Destroy(Game *game);

#endif // GAME_H