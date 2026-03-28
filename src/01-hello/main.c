// Copyright (c) 2026 Andre Kishimoto - https://kishimoto.com.br/
// SPDX-License-Identifier: Apache-2.0

//------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

//------------------------------------------------------------------------------
void shutdown(void)
{
  SDL_Log("shutdown()");
  SDL_Quit();
}

//------------------------------------------------------------------------------
int main(int argc, char *argv[])
{

  atexit(shutdown);

  const char* WINDOW_TITLE = "Hello, SDL";
  const int WINDOW_WIDTH = 640;
  const int WINDOW_HEIGHT = 480;

  if (!SDL_Init(SDL_INIT_VIDEO))
  {
    SDL_Log("Erro ao iniciar a SDL: %s", SDL_GetError());
    return SDL_APP_FAILURE;
  }

  SDL_Window *window = SDL_CreateWindow(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
  if (!window)
  {
    SDL_Log("Erro ao criar a janela: %s", SDL_GetError());
    return SDL_APP_FAILURE;
  }

  // Looping de eventos
  // O programa ficará rodando até que o usuário feche a janela
  SDL_Event event;
  bool isRunning = true;
  while (isRunning)
  {
    // Verifica se há eventos na fila de eventos
    while (SDL_PollEvent(&event))
    {
      // Se o evento for do tipo SDL_EVENT_QUIT, significa que o usuário fechou a janela
      if (event.type == SDL_EVENT_QUIT)
      {
        isRunning = false;
      }
    }
  }

  SDL_DestroyWindow(window);
  window = NULL;

  return 0;
}
