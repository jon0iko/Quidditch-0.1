#pragma once

#include "./globals.h"
#include "./events.c"

void UpdateGame()
{

    timerTime = SDL_GetTicks() - timeElapsed;
    remainingTime = (countdown > timerTime) ? countdown - timerTime : 0;

    int time = remainingTime;
    
    minutes = time / 60000;
    seconds = (time % 60000) / 1000;

    if (remainingTime == 0)
    {
        Running = FALSE;
        GameOver();
    }
    
    oldX = harry.X;
    oldY = harry.Y;
    oldAngle = harry.Angle;
    // if (Key(SDLK_f))
    // {
    //     ToggleFullscreen(window);
    // }
    if (Key(SDL_SCANCODE_SPACE))
    {
        ShootQuaffle();
    }
    if (Key(SDL_SCANCODE_UP) || Key(SDLK_w))
    {
        // movePlayerUD(-SPEED);
        // rotateBy(&harry, ROTATION);
        movePlayerLR(-SPEED);
    }
    if (Key(SDL_SCANCODE_DOWN) || Key(SDLK_s))
    {
        // movePlayerUD(SPEED);
        //rotateBy(&harry, -ROTATION);
        movePlayerLR(SPEED);
    }
    if (Key(SDL_SCANCODE_RIGHT) || Key(SDLK_d))
    {
        // movePlayerLR(-SPEED);
        rotateBy(&harry, ROTATION);
    }
    if (Key(SDL_SCANCODE_LEFT) || Key(SDLK_a))
    {
        // movePlayerLR(SPEED);
        rotateBy(&harry, -ROTATION);
    }
    if (mouseclicked == TRUE)
    {
        ShootQuaffle();
    }
    moveBludgers();
    harryMovements();
    moveQuaffles();
    hoopMovement();
    snitchBehavior();
    scoring();
}

void gameLoop(void)
{
    unsigned int LastTime, CurrentTime;

    LastTime = SDL_GetTicks();
    while (Running == TRUE)
    {

        CurrentTime = SDL_GetTicks();
        SDL_GetMouseState(&mouseX, &mouseY);
        printf("%d %d\n", mouseX, mouseY);

        if (CurrentTime - LastTime > 1000)
        {
            LastTime = CurrentTime - 60;
        }
        while (CurrentTime - LastTime > 1000 / 30)
        {
            UpdateGame();
            LastTime = LastTime + 30;
        }
        HandleEvents();
        DrawScreen();
    }
}
