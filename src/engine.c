#pragma once

#include "./globals.h"

void StartGame()
{

    lives = MAX_LIFE;

    //harry
    harry.X = 100;
    harry.Y = 100;
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
