#pragma once

#include "./globals.h"
#include "./drawing.c"

#include <stdio.h>

void MainMenu()
{
    char titleStr[20];
    char playStr[20];
    char exitStr[20];
    int keyFlag = FALSE;
    SDL_Event e;
    int tflag = FALSE;


    Mix_PlayMusic(ThemeMusic, -1); 

    SDL_RenderClear(renderer);
    Draw(0, 0, MenuBG);

    sprintf(titleStr, "Quidditch-Arcade");
    DrawText(titleStr, 125, 225, 100, 255, 255, 255, 0, 0, 0, TRUE);
    
    sprintf(playStr, "Play");
    DrawText(playStr, 70, 450, 275, 255, 255, 255, 0, 0, 0, TRUE);

    sprintf(playStr, "Instructions");
    DrawText(playStr, 70, 380, 355, 255, 255, 255, 0, 0, 0, TRUE);

    sprintf(playStr, "Leaderboard");
    DrawText(playStr, 70, 362, 435, 255, 255, 255, 0, 0, 0, TRUE);

    sprintf(playStr, "Settings");
    DrawText(playStr, 70, 415, 515, 255, 255, 255, 0, 0, 0, TRUE);

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
                    printf("%d %d\n",mouseX,mouseY);
                    if (mouseX >= 450 && mouseX <= 520 &&
                        mouseY >= 275 && mouseY <= 325)
                    {
                        keyFlag = TRUE;
                        tflag = TRUE;
                    }
                }
            }
        }
    } while (keyFlag == FALSE);

    SDL_Delay(100);
}

void StartGame()
{

    lives = MAX_LIFE;

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
}
