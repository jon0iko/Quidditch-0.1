#pragma once

#include "./globals.h"

int Key(long K){
  if ((K>= 0) && (K <= MAX_KEY)){
    return KeyState[K];
  }
  else { 
    return FALSE;
  }
}

void HandleKey(long Sym, int Down){
  if (Sym == SDLK_UP) Sym = SDL_SCANCODE_UP;
  if (Sym == SDLK_DOWN) Sym = SDL_SCANCODE_DOWN;
  if (Sym == SDLK_LEFT) Sym = SDL_SCANCODE_LEFT;
  if (Sym == SDLK_RIGHT) Sym = SDL_SCANCODE_RIGHT;
  if (Sym == SDLK_SPACE) Sym = SDL_SCANCODE_SPACE;
   if ((Sym >= 0) && (Sym <= MAX_KEY)) {
    KeyState[Sym] = Down;
    if (Sym == SDLK_ESCAPE) Running = FALSE;    
  }
} 

void HandleEvents(){
  SDL_Event e;
  if (SDL_PollEvent(&e)) {
    
    if (e.type == SDL_QUIT) {
      Running = 0;
    }

    if (e.type == SDL_KEYDOWN){
      keypressed = TRUE;
      HandleKey(e.key.keysym.sym, TRUE);
    }

    if (e.type == SDL_KEYUP){
      keypressed = FALSE;
      HandleKey(e.key.keysym.sym, FALSE);
    }  
  }
}