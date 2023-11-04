#pragma once

#include "./globals.h"
void loadComponents()
{
    background = SDL_LoadBMP("./src/img/spexpb.bmp");
    // background = IMG_Load("./src/img/QuidSky.png");
    harry.Img = IMG_Load("./src/img/harry.png");
    quaffle = IMG_Load("src/img/quaffle.png");

    if (background == NULL)
    {
        fprintf(stderr, ERR_2);
        exit(0);
    }
    if (harry.Img == NULL)
    {
        fprintf(stderr, ERR_2);
        exit(0);
    }
    if (quaffle == NULL)
    {
        fprintf(stderr, ERR_2);
        exit(0);
    }
}