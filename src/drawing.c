#pragma once

#include "./globals.h"

void Draw(int X, int Y, SDL_Surface *Img) {
  SDL_Rect R;
  SDL_Texture *textr;
  R.x = X;
  R.y = Y;
  R.w = Img->w;
  R.h = Img->h;
  textr = SDL_CreateTextureFromSurface(renderer,Img);
  SDL_RenderCopy(renderer, textr, NULL, &R);
  SDL_DestroyTexture(textr);
}

void DrawObject(OBJECT Object){
  SDL_Rect R;
  SDL_Texture *text;
  
  R.x = Object.X;
  R.y = Object.Y;
  R.w = Object.W;
  R.h = Object.H;
  text = SDL_CreateTextureFromSurface(renderer,Object.Img);
  SDL_RenderCopyEx(renderer, text, NULL, &R, Object.Angle,NULL, SDL_FLIP_NONE);
  SDL_DestroyTexture(text);
}

void DrawDynamicObject(OBJECT *Object){
  SDL_Rect R;
  SDL_Texture *text;
  
  R.x = Object->X;
  R.y = Object->Y;
  R.w = Object->W;
  R.h = Object->H;
  text = SDL_CreateTextureFromSurface(renderer,Object->Img);
  SDL_RenderCopyEx(renderer, text, NULL, &R, Object->Angle,NULL, SDL_FLIP_NONE);
  SDL_DestroyTexture(text);
}

void DrawScreen() {
  SDL_RenderClear(renderer);
  Draw(0,0,background);
  DrawObject(harry);

  if (Quaffle != NULL && length(&Quaffle) > 0) {
    for (int i=0;i<length(&Quaffle);i++){
       DrawDynamicObject(getObject(Quaffle,i));
     }
  }

  SDL_RenderPresent(renderer);
}
