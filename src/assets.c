#pragma once

#include "./globals.h"
void loadComponents()
{
    background = SDL_LoadBMP("./src/img/spexpb.bmp");

    if (background == NULL)
    {
        fprintf(stderr, ERR_2);
        exit(0);
    }

    harry.Img = IMG_Load("./src/img/harry.png");

    if (harry.Img == NULL)
    {
        fprintf(stderr, ERR_2);
        exit(0);
    }
}