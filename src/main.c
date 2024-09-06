#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    printf("SDL_Init Error: %s\n", SDL_GetError());
    return EXIT_FAILURE;
  }
  SDL_Window *window = SDL_CreateWindow("Fizzle Game!", SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED, 1600, 900, 0);

  if (!window) {
    printf("Failed to create window\n");
    SDL_Quit();
    return EXIT_FAILURE;
  }
  SDL_Surface *windowSurface = SDL_GetWindowSurface(window);

  if (!windowSurface) {  // Changed from if (windowSurface) to if (!windowSurface)
    printf("Failed to get the surface from the window\n");
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_FAILURE;
  }

  bool keepWindowOpen = true;
  while (keepWindowOpen) {
    SDL_Event e;
    while (SDL_PollEvent(&e) > 0) {
      if (e.type == SDL_QUIT) {  // Added event handling for window close
        keepWindowOpen = false;
      }
    }
    SDL_UpdateWindowSurface(window);
  }

  SDL_DestroyWindow(window);  // Added proper cleanup
  SDL_Quit();
  return EXIT_SUCCESS;
}
