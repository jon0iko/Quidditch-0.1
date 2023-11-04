#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

#include "./src/globals.h"
#include "./src/init.c"
#include "./src/assets.c"
#include "./src/physics.c"
#include "./src/engine.c"
#include "./src/drawing.c"
#include "./src/events.c"
#include "./src/gameLoop.c"
#include "./src/linkedList.c"


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
