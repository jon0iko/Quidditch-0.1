#pragma once

#include "./globals.h"

int initVid(void) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stderr, ERR_1);
        return FALSE;
    }

    // IMG_Init(IMG_INIT_PNG);

    if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
        fprintf(stderr, "SDL_image initialization failed: %s\n", IMG_GetError());
        exit(1);
    }

    window = SDL_CreateWindow("Quidditch", 
    SDL_WINDOWPOS_CENTERED, 
    SDL_WINDOWPOS_CENTERED,
    SCREEN_W,
    SCREEN_H,
    SDL_WINDOW_SHOWN);

    if (!window)
    {
        fprintf(stderr, ERR_1);
        return FALSE;
    }
    
    renderer = SDL_CreateRenderer(window,-1,0);

    SDL_SetWindowBordered(window, SDL_TRUE);

    if (!renderer)
    {
        fprintf(stderr, ERR_1);
        return FALSE;
    }

    return TRUE;
}

int initAudio() {
    if (SDL_Init(SDL_INIT_AUDIO) != 0)
    {
        fprintf(stderr, ERR_3);
        return FALSE;
    }
    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY,
    MIX_DEFAULT_FORMAT,
    MIX_DEFAULT_CHANNELS,
    4096);

    return TRUE;
}

void destroyWindow(void) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_Quit();
    IMG_Quit();
    TTF_Quit(); 
    SDL_Quit();
}