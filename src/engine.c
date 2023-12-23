#pragma once

#include "./globals.h"
#include "./drawing.c"

#include <stdio.h>

// void ToggleFullscreen(SDL_Window *Window)
// {
//     Uint32 FullscreenFlag = SDL_WINDOW_FULLSCREEN;
//     int IsFullscreen = SDL_GetWindowFlags(Window) & FullscreenFlag;
//     SDL_SetWindowFullscreen(Window, 1);
//     SDL_ShowCursor(IsFullscreen);
// }

void instructions()
{
    SDL_Event e;
    int keyFlag = FALSE;
    SDL_RenderClear(renderer);
    Draw(0, 0, ibg);
    char intro1[100];
    sprintf(intro1, "Welcome to the enchanting world of Quidditch!");
    DrawText(intro1, 55, 175, 65, 0, 0, 0, 0, 0, 0, TRUE);
    char intro2[200];
    sprintf(intro2, "In this enchanted world, a mischievous wizard cast a peculiar spell upon the goalpost.");
    DrawText(intro2, 30, 58, 130, 0, 0, 0, 0, 0, 0, TRUE);
    char intro3[200];
    sprintf(intro3, "The goalpost was enchanted to float freely in the sky, moving vertically as if dancing to an unseen melody!");
    DrawText(intro3, 30, 58, 170, 0, 0, 0, 0, 0, 0, TRUE);
    char mission[100];
    sprintf(mission, "Your Mission:");
    DrawText(mission, 45, 58, 230, 0, 0, 0, 0, 0, 0, TRUE);
    char mission1[200];
    sprintf(mission1, "Score points by tossing the Quaffle through the floating goal post while dodging dangers.");
    DrawText(mission1, 30, 75, 287, 0, 0, 0, 0, 0, 0, TRUE);
    char time[100];
    sprintf(time, "Game Duration: The match starts countdown from 2 minutes!");
    DrawText(time, 45, 58, 350, 0, 0, 0, 0, 0, 0, TRUE);
    char time1[200];
    sprintf(time1, "Scoring earns you extra time, while Bludger hits reduce your remaining time.");
    DrawText(time1, 30, 75, 407, 0, 0, 0, 0, 0, 0, TRUE);
    char score[100];
    sprintf(score, "Scoring:");
    DrawText(score, 45, 58, 445, 0, 0, 0, 0, 0, 0, TRUE);
    char score1[200];
    sprintf(score1, "Each successful Quaffle throw earns you 10 points and extra time.");
    DrawText(score1, 30, 75, 490, 0, 0, 0, 0, 0, 0, TRUE);
    char score2[200];
    sprintf(score2, "Snatch the Snitch for a whopping 50 points!");
    DrawText(score2, 30, 75, 525, 0, 0, 0, 0, 0, 0, TRUE);
    char controls[100];
    sprintf(controls, "Controls:");
    DrawText(controls, 45, 58, 563, 0, 0, 0, 0, 0, 0, TRUE);
    char controls1[200];
    sprintf(controls1, "Use left/right arrow to rotate and up/down arrow to move. Alternatively use W/A/S/D.");
    DrawText(controls1, 30, 75, 608, 0, 0, 0, 0, 0, 0, TRUE);
    char controls2[200];
    sprintf(controls2, "Press Space or Left Mouse Button to throw the Quaffle.");
    DrawText(controls2, 30, 75, 653, 0, 0, 0, 0, 0, 0, TRUE);
    char back[100];
    sprintf(back, "Back");
    DrawText(back, 45, 916, 680, 0, 0, 0, 247, 243, 210, FALSE);

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
                }
                if (mouseX >= 916 && mouseX <= 1000 &&
                    mouseY >= 680 && mouseY <= 725)
                {
                    if (soundFlag)
                    {
                        Mix_PlayChannel(3, click, 0);
                    }
                    keyFlag = TRUE;
                }
                
            }
        }
    } while (keyFlag == FALSE);

    MainMenu();
}

// void getBestScore()
// {
//     FILE *fp;
//     fp = fopen("scores.txt", "r");
//     if (fp == NULL)
//     {
//         printf("Error opening file!\n");
//         exit(1);
//     }
//     fscanf(fp, "%d", &bestScore);
//     fclose(fp);
// }

void storeScore()
{
    FILE *fp;
    fp = fopen("scores.txt", "w");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    fprintf(fp, "%d", score);
    fclose(fp);
}

int sortScores() {
    FILE *fp;
    fp = fopen("scores.txt", "r");
    int score;
    int scores[100];
    int i = 0,n = 0;
    while (fscanf(fp, "%d", &score) != EOF) {
        scores[i] = score;
        i++;
    }
    fclose(fp);

    int j;
    int temp;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (scores[i] < scores[j]) {
                temp = scores[i];
                scores[i] = scores[j];
                scores[j] = temp;
            }
        }
    }

    return scores[0];
}

void leaderboard()
{
    SDL_Event e;
    int keyFlag = FALSE;
    char scoreStr[20];
    SDL_RenderClear(renderer);
    Draw(0, 0, leaderbd);
    int best = sortScores();
    sprintf(scoreStr, "Best Score: %d", best);
    DrawText(scoreStr, 150, 200, 270, 255, 255, 255, 0, 0, 0, TRUE);

    char back[100];
    sprintf(back, "Back");
    DrawText(back, 45, 916, 680, 0, 0, 0, 247, 243, 210, FALSE);

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
                }
                if (mouseX >= 916 && mouseX <= 1000 &&
                    mouseY >= 680 && mouseY <= 725)
                {
                    if (soundFlag)
                    {
                        Mix_PlayChannel(3, click, 0);
                    }
                    keyFlag = TRUE;
                }
                
            }
        }
    } while (keyFlag == FALSE);

    MainMenu();
}

void settings() {
    SDL_Event e;
    int keyFlag = FALSE;
    SDL_RenderClear(renderer);
    Draw(0, 0, settingsbg);
    char sound[100];
    sprintf(sound, "Sound");
    DrawText(sound, 45, 58, 65, 0, 0, 0, 0, 0, 0, TRUE);
    char sound1[200];
    sprintf(sound1, "Turn sound on/off");
    DrawText(sound1, 30, 75, 120, 0, 0, 0, 0, 0, 0, TRUE);
    char sound2[200];
    sprintf(sound2, "Current status: %s", soundFlag ? "ON" : "OFF");
    DrawText(sound2, 30, 75, 155, 0, 0, 0, 0, 0, 0, TRUE);
    char difficulty[100];
    sprintf(difficulty, "Difficulty");
    DrawText(difficulty, 45, 58, 210, 0, 0, 0, 0, 0, 0, TRUE);
    char difficulty1[200];
    sprintf(difficulty1, "Set difficulty level");
    DrawText(difficulty1, 30, 75, 265, 0, 0, 0, 0, 0, 0, TRUE);
    char difficulty2[200];
    sprintf(difficulty2, "HARD");
    DrawText(difficulty2, 35, 75, 300, 0, 0, 0, 0, 0, 0, TRUE);
    char difficulty3[200];
    sprintf(difficulty3, "EASY");
    DrawText(difficulty3, 35, 75, 350, 0, 0, 0, 0, 0, 0, TRUE);


    char back[100];
    sprintf(back, "Back");
    DrawText(back, 45, 916, 680, 0, 0, 0, 247, 243, 210, FALSE);

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
                }
                if (mouseX >= 916 && mouseX <= 1000 &&
                    mouseY >= 680 && mouseY <= 725)
                {
                    if (soundFlag)
                    {
                        Mix_PlayChannel(3, click, 0);
                    }
                    keyFlag = TRUE;
                }
                if (mouseX >= 75 && mouseX <= 140 &&
                    mouseY >= 300 && mouseY <= 329)
                {
                    if (soundFlag)
                    {
                        Mix_PlayChannel(3, click, 0);
                    }
                    difficultyFlag = 1;
                }

                if (mouseX >= 75 && mouseX <= 140 &&
                    mouseY >= 350 && mouseY <= 379)
                {
                    if (soundFlag)
                    {
                        Mix_PlayChannel(3, click, 0);
                    }
                    difficultyFlag = 0;
                }       
                
            }
        }
    } while (keyFlag == FALSE);

    

    MainMenu();

}

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

    Mix_PlayMusic(introMusic, -1);

    SDL_RenderClear(renderer);
    Draw(0, 0, MenuBG);

    sprintf(titleStr, "Quidditch-Arcade");
    DrawText(titleStr, 125, 225, 100, 255, 255, 255, 0, 0, 0, TRUE);

    sprintf(playStr, "Play");
    DrawText(playStr, 70, 450, 275, 255, 255, 255, 0, 0, 0, TRUE);

    sprintf(instructStr, "Instructions");
    DrawText(instructStr, 70, 380, 355, 255, 255, 255, 0, 0, 0, TRUE);

    sprintf(leaderStr, "Best Scores");
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
                        if (soundFlag)
                        {
                            Mix_PlayChannel(3, click, 0);
                        }
                        keyFlag = TRUE;
                    }
                    if (mouseX >= 368 && mouseX <= 591 &&
                        mouseY >= 366 && mouseY <= 416)
                    {
                        if (soundFlag)
                        {
                            Mix_PlayChannel(3, click, 0);
                        }
                        instructions();
                    }
                    if (mouseX >= 362 && mouseX <= 595 &&
                        mouseY >= 438 && mouseY <= 503)
                    {
                        if (soundFlag)
                        {
                            Mix_PlayChannel(3, click, 0);
                        }
                        leaderboard();
                    }
                    if (mouseX >= 415 && mouseX <= 571 &&
                        mouseY >= 525 && mouseY <= 585)
                    {
                        if (soundFlag)
                        {
                            Mix_PlayChannel(3, click, 0);
                        }
                        settings();
                    }
                    if (mouseX >= 450 && mouseX <= 535 &&
                        mouseY >= 603 && mouseY <= 656)
                    {
                        if (soundFlag)
                        {
                            Mix_PlayChannel(3, click, 0);
                        }
                        Running = FALSE;
                        return;
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
    Mix_HaltMusic();
    Mix_PlayMusic(gameMusic, -1);
    int i, a, tDIRX, tDIRY, tX, tY;
    timeFlag = TRUE;
    timeElapsed = SDL_GetTicks();
    int bludge;

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

    // hoop
    hoop1.X = 945;
    hoop1.Y = 393;
    hoop1.W = 62;
    hoop1.H = 227;

    // box
    box.X = 949;
    box.Y = 397;
    box.W = 55;
    box.H = 55;

    // clock
    clockk.X = 413;
    clockk.Y = 5;
    clockk.W = 25;
    clockk.H = 25;


    if (difficultyFlag == 0) {
        bludge = 5;
    }
    else {
        bludge = 10;
    }
    

    srand((unsigned)time(NULL));

    for (i = 0; i < bludge; i++)
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

void GameOver()
{
    Mix_HaltMusic();
    if (soundFlag)
    {
        Mix_PlayChannel(4, endgame, 0);
    }
    storeScore();
    char gameOverStr[20];
    char scoreStr[20];
    char exitStr[20];
    char menu[20];
    int keyFlag = FALSE;
    SDL_Event e;

    SDL_RenderClear(renderer);
    Draw(0, 0, gOver);

    sprintf(gameOverStr, "Game Over");
    DrawText(gameOverStr, 135, 307, 60, 0, 0, 0, 126, 229, 242, TRUE);

    sprintf(scoreStr, "Score: %d", score);
    DrawText(scoreStr, 70, 450, 351, 0, 0, 0, 0, 0, 0, TRUE);

    sprintf(exitStr, "Exit");
    DrawText(exitStr, 70, 270, 640, 255, 255, 255, 0, 0, 0, TRUE);

    sprintf(menu, "Menu");
    DrawText(menu, 70, 610, 640, 255, 255, 255, 0, 0, 0, TRUE);

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
                    if (mouseX >= 270 && mouseX <= 351 &&
                        mouseY >= 647 && mouseY <= 687)
                    {
                        if (soundFlag)
                        {
                            Mix_PlayChannel(3, click, 0);
                        }
                        Running = FALSE;
                        return;
                    }

                    if (mouseX >= 610 && mouseX <= 713  &&
                        mouseY >= 640 && mouseY <= 690)
                    {
                        if (soundFlag)
                        {
                            Mix_PlayChannel(3, click, 0);
                        }
                        keyFlag = TRUE;
                        MainMenu();
                    }
                }
            }
        }
    } while (keyFlag == FALSE);

    SDL_Delay(100);

}