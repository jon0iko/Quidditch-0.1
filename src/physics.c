#pragma once

#include "./globals.h"
#include "./linkedList.c"
#include <math.h>

double sinD(int degree)
{
   double ret, val;
   val = PI / 180;
   ret = sin(degree * val);
   return ret;
}

double cosD(int degree)
{
   double ret, val;
   val = PI / 180;
   ret = cos(degree * val);
   return ret;
}

int collision(int AX1, int AY1, int AX2, int AY2, int BX1, int BY1, int BX2, int BY2)
{
   return (AX1 < BX1 + (BX2 - BX1)) && (AX1 + (AX2 - AX1) > BX1) && (AY1 < BY1 + (BY2 - BY1)) && (AY1 + (AY2 - AY1) > BY1);
}

// harry.X + 5, harry.Y + 5, harry.X + harry.W - 5, harry.Y + harry.H - 5, p->X, p->Y, p->X + p->W, p->Y + p->H

void movePlayerUD(int speed)
{

   harry.DX = harry.DX + (speed * sinD(harry.Angle)) * -1;
   harry.DY = harry.DY + (speed * cosD(harry.Angle));
   harry.X = round(harry.DX);
   harry.Y = round(harry.DY);
}

void movePlayerLR(int speed)
{

   harry.DX = harry.DX + (speed * sinD(harry.Angle + 90)) * -1;
   harry.DY = harry.DY + (speed * cosD(harry.Angle + 90));
   harry.X = round(harry.DX);
   harry.Y = round(harry.DY);
}

void rotateBy(OBJECT *Object, float rotation)
{
   float temp;

   if (fabs(Object->Angle + rotation))
   {
      temp = Object->Angle + rotation;
      Object->Angle = round(temp);
   }
   else
   {
      Object->Angle = Object->Angle * -1;
   }
}

void harryMovements()
{
   if (harry.Y < 0)
   {
      harry.Y = 0;
      harry.DY = 0;
   }
   if (harry.Y + harry.H > SCREEN_H)
   {
      harry.Y = SCREEN_H - harry.H;
      harry.DY = SCREEN_H - harry.H;
   }
   if (harry.X + harry.W > SCREEN_W)
   {
      harry.X = SCREEN_W - harry.W;
      harry.DX = SCREEN_W - harry.W;
   }
   if (harry.X < 0)
   {
      harry.X = 0;
      harry.DX = 0;
   }
}

void LaunchProjectile(double X, double Y, double DX, double DY, SDL_Surface *Img, int Life)
{
   OBJECT p;
   if (Quaffle == NULL)
      p.index = 0;
   else
   {
      p.index = length(&Quaffle);
   }
   p.Img = Img;
   p.Angle = harry.Angle + 90;
   p.W = 16;
   p.H = 16;
   if (Life == -1)
   {
      // harry quaffle
      p.FX = (harry.X + (harry.W - 10) / 2) + ((cosD(p.Angle) * -1) - (sinD(p.Angle) * 40) * -1);
      p.FY = (harry.Y + (harry.H - 30) / 2) + (sinD(p.Angle) * -1) + ((cosD(p.Angle) * 40 * -1));
      p.DX = DX;
      p.DY = DY;
      p.X = round(p.FX);
      p.Y = round(p.FY);
   }
   else
   {
      p.X = X;
      p.Y = Y;
      p.FX = X;
      p.FY = Y;
      p.DX = DX;
      p.DY = DY;
   }

   p.Life = Life;
   Quaffle = addend(Quaffle, newelement(p));
}

void moveQuaffles()
{
   OBJECT *p, *a;
   for (int i = 0; i < length(&Quaffle); i++)
   {
      p = getObject(Quaffle, i);
      if (p->Life == -1)
      {
         p->FX = p->FX + (p->DX * sinD(p->Angle));
         p->FY = p->FY + (p->DY * cosD(p->Angle)) * -1;
         p->X = round(p->FX);
         p->Y = round(p->FY);
      }

      for (int j = 0; j < length(&bludgers); j++)
      {
         a = getObject(bludgers, j);
         // Collision with bludgers
         if (collision(p->X, p->Y, p->X + p->W, p->Y + p->H, a->X, a->Y,
                       a->X + a->W, a->Y + a->H) &&
             p->Life == -1)
         {
            deleteObject(&Quaffle, i, TRUE);
            break;
         }
      }

      if (p->Y < -10 || p->Y > SCREEN_H + 10 || p->X < -10 || p->X > SCREEN_W + 10 || p->Life == 0)
      {
         deleteObject(&Quaffle, i, TRUE);
         continue;
      }
   }
}

void ShootQuaffle()
{
   if (SDL_GetTicks() - shootTime < 500)
   {
      // Wait
   }
   else
   {
      shootTime = SDL_GetTicks();

      LaunchProjectile(harry.X + 16, harry.Y - 2, 20, 20, quaffle, -1);
   }
}

void moveBludgers()
{

   int i;
   OBJECT *p;

   for (i = 0; i < length(&bludgers); i++)
   {
      p = getObject(bludgers, i);
      p->DX = p->DX + (5.5 * p->DIRX);
      p->DY = p->DY + (5.5 * p->DIRY);
      p->X = round(p->DX);
      p->Y = round(p->DY);
      p->Angle += 3.5;

      if (harry.X != 100 && harry.Y != 100)
      {
         if (collision(harry.X + 5, harry.Y + 5, harry.X + harry.W - 5, harry.Y + harry.H - 5, p->X, p->Y, p->X + p->W, p->Y + p->H))
         {
            collisionTimer = SDL_GetTicks();
            collisionFlag = TRUE;
            harry.X = 100;
            harry.Y = 100;
            harry.DX = 100;
            harry.DY = 100;
            harry.Angle = 0;
         }
      }

      if (p->Y < -10)
      {
         p->Y = SCREEN_H;
         p->DY = SCREEN_H;
      }
      if (p->Y > SCREEN_H + 10)
      {
         p->Y = 0;
         p->DY = 0;
      }
      if (p->X > SCREEN_W + 10)
      {
         p->X = 0;
         p->DX = 0;
      }
      if (p->X < -10)
      {
         p->X = SCREEN_W;
         p->DX = SCREEN_W;
      }

      // if (p->Y > SCREEN_H)
      // {
      //    p->Y = SCREEN_H;
      //    p->DY = SCREEN_H;
      // }
      // if (p->Y < 0)
      // {
      //    p->Y = 0;
      //    p->DY = 0;
      // }
      // if (p->X < 0)
      // {
      //    p->X = 0;
      //    p->DX = 0;
      // }
      // if (p->X > SCREEN_W)
      // {
      //    p->X = SCREEN_W;
      //    p->DX = SCREEN_W;
      // }
   }
}

void hoopMovement()
{
   if (upflag == 1)
   {
      hoop1.Y -= 5;
   }
   else if (downflag == 1)
   {
      hoop1.Y += 5;
   }
   
   if (hoop1.Y < 68)
   {
      hoop1.Y += 5;
      upflag = 0;
      downflag = 1;
   }
   if (hoop1.Y + hoop1.H > SCREEN_H)
   {
      hoop1.Y -= 5;
      downflag = 0;
      upflag = 1;
   }
}