#pragma once

#include "./globals.h"
#include "./events.c"

void UpdateGame()
{
    oldX = harry.X;
    oldY = harry.Y;
    oldAngle = harry.Angle;
    if (Key(SDLK_f))
    {
        ToggleFullscreen(window);
    }
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
        rotateBy(&harry, -ROTATION);
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
}

void gameLoop(void)
{
    unsigned int LastTime, CurrentTime, timerTime;

    LastTime = SDL_GetTicks();
    while (Running == TRUE)
    {
        CurrentTime = SDL_GetTicks();
        SDL_GetMouseState(&mouseX, &mouseY);
        printf("%d %d\n", mouseX, mouseY);

        timerTime = SDL_GetTicks() - timeElapsed;
        remainingTime = (countdown > timerTime) ? countdown - timerTime : 0;

        minutes = remainingTime / 60000;
        seconds = (remainingTime % 60000) / 1000;

        if (collisionFlag == 1)
        {
            unsigned int elapsedTime = CurrentTime - collisionTimer;
            if (elapsedTime >= 500)
            {
                collisionFlag = FALSE;
                collisionTimer = 0;
            }
        }

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
