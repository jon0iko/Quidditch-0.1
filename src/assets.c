#pragma once

#include "./globals.h"
void loadComponents()
{
    //image
    background = IMG_Load("./src/img/bgm.png");
    harry.Img = IMG_Load("./src/img/harry.png");
    quaffle = IMG_Load("src/img/quaffle.png");
    MenuBG = IMG_Load("src/img/bgg.png");
    bludger = IMG_Load("src/img/bludger.png");
    hoop1.Img = IMG_Load("src/img/225Asset 6.png");
    snitch.Img = IMG_Load("src/img/snitch.png");

    //hoop sprite
    hoopSprite[0].Img = IMG_Load("src/img/225Asset 6.png");
    hoopSprite[1].Img = IMG_Load("src/img/250Asset 7.png");
    hoopSprite[2].Img = IMG_Load("src/img/275Asset 8.png");
    hoopSprite[3].Img = IMG_Load("src/img/300Asset 9.png");
    hoopSprite[4].Img = IMG_Load("src/img/325Asset 10.png");
    hoopSprite[5].Img = IMG_Load("src/img/350Asset 11.png");
    hoopSprite[6].Img = IMG_Load("src/img/375Asset 12.png");
    hoopSprite[7].Img = IMG_Load("src/img/400Asset 13.png");

    //music
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