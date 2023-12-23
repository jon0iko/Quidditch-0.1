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
    snitch = IMG_Load("src/img/snitchUp.png");
    snitch2 = IMG_Load("src/img/snitchDown.png");
    box.Img = IMG_Load("src/img/box.png");
    ibg = IMG_Load("src/img/textbg.jpeg");
    leaderbd = IMG_Load("src/img/leaderbd.jpeg");
    clockk.Img = IMG_Load("src/img/clockk.png");
    gOver = IMG_Load("src/img/end.jpeg");
    settingsbg = IMG_Load("src/img/settings.png");

    //hoop sprite
    // hoopSprite[0].Img = IMG_Load("src/img/225Asset 6.png");
    // hoopSprite[1].Img = IMG_Load("src/img/250Asset 7.png");
    // hoopSprite[2].Img = IMG_Load("src/img/275Asset 8.png");
    // hoopSprite[3].Img = IMG_Load("src/img/300Asset 9.png");
    // hoopSprite[4].Img = IMG_Load("src/img/325Asset 10.png");
    // hoopSprite[5].Img = IMG_Load("src/img/350Asset 11.png");
    // hoopSprite[6].Img = IMG_Load("src/img/375Asset 12.png");
    // hoopSprite[7].Img = IMG_Load("src/img/400Asset 13.png");

    //snitch sprite
    snitchSprite[0].Img = IMG_Load("src/img/snitchUp.png");
    snitchSprite[1].Img = IMG_Load("src/img/snitchDown.png");

    //music
    gameMusic = Mix_LoadMUS("./src/audio/main.mp3");
    introMusic = Mix_LoadMUS("./src/audio/intro.mp3");
    bludgerHit = Mix_LoadWAV("./src/audio/bludgerHit.wav");
    Mix_VolumeChunk(bludgerHit, volume/2);
    bludgerCollision = Mix_LoadWAV("./src/audio/bludgerCollision.wav");
    Mix_VolumeChunk(bludgerCollision, volume/2);
    click = Mix_LoadWAV("./src/audio/click.wav");
    Mix_VolumeChunk(click, volume);
    endgame = Mix_LoadWAV("./src/audio/endgame.wav");
    Mix_VolumeChunk(endgame, volume);
    hoopScore = Mix_LoadWAV("./src/audio/hoopScore.wav");
    Mix_VolumeChunk(hoopScore, volume);
    snitchCaught = Mix_LoadWAV("./src/audio/snitch.wav");
    Mix_VolumeChunk(snitchCaught, volume);
    throw = Mix_LoadWAV("./src/audio/throw.wav");
    Mix_VolumeChunk(throw, volume);

    //error handling
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