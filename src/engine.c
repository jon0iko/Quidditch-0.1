#pragma once

#include "./globals.h"
#include "./drawing.c"

#include <stdio.h>

void MainMenu()
{
    char titleStr[20];
    char playStr[20];
    char instructStr[20];
    char leaderStr[20];
    char settingsStr[20];
    char exitStr[20];
    int keyFlag = FALSE;
    SDL_Event e;

    Mix_PlayMusic(ThemeMusic, -1);

    SDL_RenderClear(renderer);
    Draw(0, 0, MenuBG);

    sprintf(titleStr, "Quidditch-Arcade");
    DrawText(titleStr, 125, 225, 100, 255, 255, 255, 0, 0, 0, TRUE);

    sprintf(playStr, "Play");
    DrawText(playStr, 70, 450, 275, 255, 255, 255, 0, 0, 0, TRUE);

    sprintf(instructStr, "Instructions");
    DrawText(instructStr, 70, 380, 355, 255, 255, 255, 0, 0, 0, TRUE);

    sprintf(leaderStr, "Leaderboard");
    DrawText(leaderStr, 70, 362, 435, 255, 255, 255, 0, 0, 0, TRUE);

    sprintf(settingsStr, "Settings");
    DrawText(settingsStr, 70, 415, 515, 255, 255, 255, 0, 0, 0, TRUE);

    sprintf(exitStr, "Exit");
    DrawText(exitStr, 70, 450, 595, 255, 255, 255, 0, 0, 0, TRUE);

    SDL_RenderPresent(renderer);

    do
    {
        if (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                Running = FALSE;
                break;
            }
            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                if (e.button.button == SDL_BUTTON_LEFT)
                {
                    SDL_GetMouseState(&mouseX, &mouseY);
                    printf("%d %d\n", mouseX, mouseY);
                    if (mouseX >= 450 && mouseX <= 520 &&
                        mouseY >= 275 && mouseY <= 325)
                    {
                        keyFlag = TRUE;
                    }
                }
            }
        }
    } while (keyFlag == FALSE);

    SDL_Delay(100);
}

void addBludger(int X, int Y, int DIRX, int DIRY)
{
    OBJECT temp;
    temp.index = length(&bludgers);
    temp.DIRX = DIRX;
    temp.DIRY = DIRY;
    temp.X = X;
    temp.Y = Y;
    temp.DX = temp.X;
    temp.DY = temp.Y;

    temp.W = 16;
    temp.H = 16;
    temp.Life = 3;
    temp.Angle = 0;
    temp.Img = bludger;
    bludgers = addend(bludgers, newelement(temp));
}

void StartGame()
{
    int i, a, tDIRX, tDIRY, tX, tY;
    // lives = MAX_LIFE;

    // harry
    harry.X = 450;
    harry.Y = 350;
    oldX = harry.X;
    oldY = harry.Y;
    harry.DX = harry.X;
    harry.DY = harry.Y;
    harry.W = 125;
    harry.H = 70;
    harry.Angle = 0;
    oldAngle = harry.Angle;
    harryStill = TRUE;

    srand((unsigned)time(NULL));

    for (i = 0; i < 3; i++)
    {
        a = rand() % 2;
        if (a == 0)
            tDIRX = 1;
        else
            tDIRX = -1;
        a = rand() % 2;
        if (a == 0)
            tDIRY = 1;
        else
            tDIRY = -1;
        tX = rand() % SCREEN_W;
        tY = rand() % SCREEN_H;
        addBludger(tX, tY, tDIRX, tDIRY);
    }
}
