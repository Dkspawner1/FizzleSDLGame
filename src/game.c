#include "game.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct GameState
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool running;
} GameState;

static GameState gameState;

static bool Initialize(Game *self);
static void HandleEvents(Game *self);
static void Update(Game *self);
static void Render(Game *self);
static void Clean(Game *self);
static bool IsRunning(Game *self);

Game *Create()
{
    Game *game = (Game *)malloc(sizeof(Game));
    if (game == NULL)
    {
        fprintf(stderr, "Failed to allocate memory for Game\n");
        return NULL;
    }
    game->init = Initialize;
    game->handleEvents = HandleEvents;
    game->update = Update;
    game->render = Render;
    game->clean = Clean;
    game->isRunning = IsRunning;
    return game;
}

void Destroy(Game *game)
{
    if (game != NULL)
    {
        free(game);
    }
}

static bool Initialize(Game *self)
{
    (void)self; // Suppress unused parameter warning
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }
    gameState.window = SDL_CreateWindow("SDL Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600, 900, SDL_WINDOW_SHOWN);
    if (gameState.window == NULL)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    gameState.renderer = SDL_CreateRenderer(gameState.window, -1, SDL_RENDERER_ACCELERATED);
    if (gameState.renderer == NULL)
    {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }
    gameState.running = true;
    return true;
}

static void HandleEvents(Game *self)
{
    (void)self; // Suppress unused parameter warning
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == (Uint32)SDL_QUIT)
            gameState.running = false;
    }
}

static void Update(Game *self)
{
    (void)self; // Suppress unused parameter warning
    // Update game logic here
}

static void Render(Game *self)
{
    (void)self; // Suppress unused parameter warning
    SDL_SetRenderDrawColor(gameState.renderer, 255, 20, 147, 255);
    SDL_RenderClear(gameState.renderer);

    // Render game objects here

    SDL_RenderPresent(gameState.renderer);
}

static void Clean(Game *self)
{
    (void)self; // Suppress unused parameter warning
    SDL_DestroyRenderer(gameState.renderer);
    SDL_DestroyWindow(gameState.window);
    SDL_Quit();
}

static bool IsRunning(Game *self)
{
    (void)self; // Suppress unused parameter warning
    return gameState.running;
}