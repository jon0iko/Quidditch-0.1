#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

#include "./globals.h"
#include "./init.c"
#include "./assets.c"
#include "./physics.c"
#include "./engine.c"
#include "./drawing.c"
#include "./events.c"
#include "./gameLoop.c"


int main()
{
    initVid();
    initAudio();
    TTF_Init();
    loadComponents();
    StartGame();
    gameLoop();
    destroyWindow();
    return 0;
}