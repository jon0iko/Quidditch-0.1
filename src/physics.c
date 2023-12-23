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
   if (harry.X + harry.W > 890)
   {
      harry.X = 890 - harry.W;
      harry.DX = 890 - harry.W;
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
            if (soundFlag)
            {
               Mix_PlayChannel(-1, bludgerCollision, 0);
            }
            
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
      if (soundFlag)
      {
         Mix_PlayChannel(7, throw, 0);
      }
      
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
            countdown -= 3000;

            if (soundFlag == TRUE)
            {
               Mix_PlayChannel(-1, bludgerHit, 0);
            }

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
   }
}

void hoopMovement()
{

   int diff;

   if (difficultyFlag == 0)
   {
      diff = 5;
   }
   else if (difficultyFlag == 1)
   {
      diff = 10;
   }
   

   if (upflag == 1)
   {
      hoop1.Y -= diff;
      box.Y -= diff;
   }
   else if (downflag == 1)
   {
      hoop1.Y += diff;
      box.Y += diff;
   }

   if (hoop1.Y < 68)
   {
      hoop1.Y += diff;
      box.Y += diff;
      upflag = 0;
      downflag = 1;
   }
   if (hoop1.Y + hoop1.H > SCREEN_H)
   {
      hoop1.Y -= diff;
      box.Y -= diff;
      downflag = 0;
      upflag = 1;
   }
}

void scoring()
{
   OBJECT *p, *q;
   for (int i = 0; i < length(&Quaffle); i++)
   {
      p = getObject(Quaffle, i);
      if (collision(p->X, p->Y, p->X + p->W, p->Y + p->H, box.X, box.Y, box.X + box.W, box.Y + box.H))
      {
         if (soundFlag == TRUE)
         {
            Mix_PlayChannel(5, hoopScore, 0);
         }
         score += 10;
         p->X += 15;
         deleteObject(&Quaffle, i, TRUE);
         countdown += 2000;
         break;
      }
   }

   if (snitchFlag == TRUE)
   {
      q = getObject(SNITCH, 0);
      if (collision(harry.X, harry.Y, harry.X + harry.W, harry.Y + harry.H, q->X, q->Y, q->X + q->W, q->Y + q->H))
      {
         if (soundFlag == TRUE)
         {
            Mix_PlayChannel(6, snitchCaught, 0);
         }
         score += 60;
         deleteObject(&SNITCH, 0, TRUE);
         free(SNITCH);
         snitchFlag = FALSE;
         sdrawn = FALSE;
         countdown += 3000;
      }
   }
}

void generateSnitch()
{

   OBJECT p;
   int x, y;

   p.index = 0;
   p.Img = snitch;
   p.W = 40;
   p.H = 19;
   p.Angle = 0;

   srand((unsigned)time(NULL));
   int minDistance = 15;
   do
   {
      x = rand() % (860);
      y = rand() % (740);
      if (y < 60)
      {
         y += 60;
      }

      int distanceX = abs(x - harry.X);
      int distanceY = abs(y - harry.Y);

      float distance = sqrt((distanceX * distanceX) + (distanceY * distanceY));

      if (distance >= minDistance)
      {
         break;
      }

   } while (1);

   p.X = x;
   p.Y = y;
   SNITCH = addend(SNITCH, newelement(p));
}

void toggleSnitchTexture()
{
   OBJECT *p;

   p = getObject(SNITCH, 0);
   if (frame % snitchAnimationSpeed == 0)
   {
      if (p->Img == snitchSprite[0].Img)
      {
         p->Img = snitchSprite[1].Img;
      }
      else
      {
         p->Img = snitchSprite[0].Img;
      }
   }
   frame++;
}

void snitchBehavior()
{
   if (score % 50 == 0 && score != 0 && score > prevScore)
   {
      snitchFlag = TRUE;
   }

   if (snitchFlag == TRUE && sdrawn == FALSE)
   {
      generateSnitch();
      prevScore = score;
      
      snitchTimer = SDL_GetTicks();
      sdrawn = TRUE;
   }
   if (sdrawn == TRUE)
   {
      toggleSnitchTexture();
   }
}