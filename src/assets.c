#pragma once

#include "./globals.h"
void loadComponents()
{
    // background = SDL_LoadBMP("./src/img/QuidSky.bmp");
    background = IMG_Load("./src/img/background.bmp");
    harry.Img = IMG_Load("./src/img/harry.png");
    quaffle = IMG_Load("src/img/quaffle.png");
    MenuBG = IMG_Load("src/img/bgg.png");
    bludger = IMG_Load("src/img/bludger.png");

    ThemeMusic = Mix_LoadMUS("./src/audio/ThemeMusic.mp3");


    if (ThemeMusic == NULL)
    {
        fprintf(stderr, ERR_3);
        exit(0);
    }
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
    if (MenuBG == NULL)
    {
        fprintf(stderr, ERR_2);
        exit(0);
    }
}