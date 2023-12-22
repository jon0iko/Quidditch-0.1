#pragma once

#include "./globals.h"

void DrawText(char *string, int size, int x, int y, int fR, int fG, int fB, int bR, int bG, int bB, int transparent)
{

  // if (TTF_Init == NULL) exit(0);

  TTF_Font *font = TTF_OpenFont("src/font/HARRYP__.TTF", size);

  SDL_Color foregroundColor = {fR, fG, fB, 0};
  SDL_Color backgroundColor = {bR, bG, bB, 0};
  SDL_Surface *textSurface;

  if (transparent == TRUE)
    textSurface = TTF_RenderText_Blended(font, string, foregroundColor);
  else
    textSurface = TTF_RenderText_Shaded(font, string, foregroundColor, backgroundColor);

  SDL_Texture *texture1 = SDL_CreateTextureFromSurface(renderer, textSurface);

  SDL_Rect textLocation = {x, y, textSurface->w, textSurface->h};

  SDL_RenderCopy(renderer, texture1, NULL, &textLocation);

  SDL_FreeSurface(textSurface);
  SDL_DestroyTexture(texture1);

  TTF_CloseFont(font);
}

void Draw(int X, int Y, SDL_Surface *Img)
{
  SDL_Rect R;
  SDL_Texture *textr;
  R.x = X;
  R.y = Y;
  R.w = SCREEN_W;
  R.h = SCREEN_H;
  textr = SDL_CreateTextureFromSurface(renderer, Img);
  SDL_RenderCopy(renderer, textr, NULL, &R);
  SDL_DestroyTexture(textr);
}

void DrawObject(OBJECT Object)
{
  SDL_Rect R;
  SDL_Texture *text;

  R.x = Object.X;
  R.y = Object.Y;
  R.w = Object.W;
  R.h = Object.H;
  text = SDL_CreateTextureFromSurface(renderer, Object.Img);
  SDL_RenderCopyEx(renderer, text, NULL, &R, Object.Angle, NULL, SDL_FLIP_NONE);
  SDL_DestroyTexture(text);
}

void DrawDynamicObject(OBJECT *Object)
{
  SDL_Rect R;
  SDL_Texture *text;

  R.x = Object->X;
  R.y = Object->Y;
  R.w = Object->W;
  R.h = Object->H;
  text = SDL_CreateTextureFromSurface(renderer, Object->Img);
  SDL_RenderCopyEx(renderer, text, NULL, &R, Object->Angle, NULL, SDL_FLIP_NONE);
  SDL_DestroyTexture(text);
}

void DrawLife()
{
  SDL_Rect rect;
  rect.x = 80;
  rect.y = 10;
  rect.w = (remainingTime / 1000) * 1.25;
  rect.h = 15;
  if (remainingTime > 0)
  {
    SDL_SetRenderDrawColor(renderer, 118, 36, 3, 0);
    SDL_RenderDrawRect(renderer, &rect);
    SDL_RenderFillRect(renderer, &rect);
  }
}

void DrawScreen()
{
  SDL_RenderClear(renderer);
  Draw(0, 0, background);

  char timerText[32], scoreText[32];
  sprintf(timerText, "%02d:%02d", minutes, seconds);
  DrawText(timerText, 32, 1, 1, 255, 255, 255, 0, 0, 0, TRUE);
  sprintf(scoreText, "Score: %02d", seconds);
  DrawText(scoreText, 32, 900, 1, 255, 255, 255, 0, 0, 0, TRUE);

  DrawObject(harry);
  DrawObject(hoop1);
  // DrawObject(snitch);

  if (bludgers != NULL)
  {
    for (int i = 0; i < length(&bludgers); i++)
    {
      DrawDynamicObject(getObject(bludgers, i));
    }
  }

  if (Quaffle != NULL && length(&Quaffle) > 0)
  {
    for (int i = 0; i < length(&Quaffle); i++)
    {
      DrawDynamicObject(getObject(Quaffle, i));
    }
  }
  DrawLife();
  SDL_RenderPresent(renderer);
}
