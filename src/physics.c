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

void rotateBy(OBJECT *Object, float D)
{
   float temp;

   if (fabs(Object->Angle + D) < 181)
   {
      temp = Object->Angle + D;
      Object->Angle = round(temp);
   }
   else
   {
      Object->Angle = Object->Angle * -1;
   }
}

void harryMovements()
{
   if (harry.Y < -10)
   {
      harry.Y = SCREEN_H;
      harry.DY = SCREEN_H;
   }
   if (harry.Y > SCREEN_H + 10)
   {
      harry.Y = 0;
      harry.DY = 0;
   }
   if (harry.X > SCREEN_W + 10)
   {
      harry.X = 0;
      harry.DX = 0;
   }
   if (harry.X < -10)
   {
      harry.X = SCREEN_W;
      harry.DX = SCREEN_W;
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
      // poof explosion animation
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

void moveProjectiles()
{
   OBJECT *p;
   for (int i = 0; i < length(&Quaffle); i++)
   {
      p = getObject(Quaffle, i);
      // Vector rotation
      if (p->Life == -1)
      {
         p->FX = p->FX + (p->DX * sinD(p->Angle));
         p->FY = p->FY + (p->DY * cosD(p->Angle)) * -1;
         p->X = round(p->FX);
         p->Y = round(p->FY);
      }
      if (p->Life != -1)
         p->Life = p->Life - 1;
      if (p->Y < -10 || p->Y > SCREEN_H + 10 || p->X < -10 || p->X > SCREEN_W + 10 || p->Life == 0)
      {
         deleteObject(&Quaffle, i, TRUE);
         continue;
      }
   }
}

void ShootQuaffle()
{
   if (SDL_GetTicks() - shootTime < 100)
   {
      // Do nothing
   }
   else
   {
      shootTime = SDL_GetTicks();

      LaunchProjectile(harry.X + 16, harry.Y - 2, 20, 20, quaffle, -1);
   }
}