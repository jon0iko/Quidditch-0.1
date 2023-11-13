#pragma once

#include "./globals.h"
#include "./events.c"

void UpdateGame() {
    oldX = harry.X;
    oldY = harry.Y;
    oldAngle = harry.Angle;
    if (Key(SDL_SCANCODE_SPACE)) {ShootQuaffle();}
    if (Key(SDL_SCANCODE_UP) || Key(SDLK_w)) {movePlayerUD(-SPEED);}
    if (Key(SDL_SCANCODE_DOWN) || Key(SDLK_s)) {movePlayerUD(SPEED);}
    if (Key(SDL_SCANCODE_RIGHT) || Key(SDLK_d)) {movePlayerLR(-SPEED);}
    if (Key(SDL_SCANCODE_LEFT) || Key(SDLK_a)) {movePlayerLR(SPEED);}
    if (Key(SDL_SCANCODE_PAGEDOWN) || Key(SDLK_c)) {rotateBy(&harry, ROTATION);} //ROTATION=5.5
    if (Key(SDL_SCANCODE_PAGEUP) || Key(SDLK_z)) {rotateBy(&harry, -ROTATION);}
    if (mouseclicked == TRUE) {ShootQuaffle();}
    harryMovements();
    moveProjectiles();
}

void gameLoop(void)
{
    unsigned int LastTime, CurrentTime;

    LastTime = SDL_GetTicks();
    while (Running == TRUE)
    {
        CurrentTime = SDL_GetTicks();
        if (CurrentTime - LastTime > 1000) {
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

