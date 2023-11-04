#pragma once

#define TRUE 1
#define FALSE 0
#define SCREEN_W 1024
#define SCREEN_H 768
#define MSG_S "SDL Graphics loaded successfully.\n"
#define ERR_1 "SDL Graphics loading failed. \n"
#define ERR_2 "Failed to load asset. \n"
#define ERR_3 "SDL Audio loading failed. \n"
#define MAX_KEY 1000
#define UP 9
#define DOWN 10
#define SPEED 12
#define ROTATION 5.5
#define MAX_LIFE 100
#define MAX_KEY 1000
#define PI 3.14159265


SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Surface *background = NULL;
SDL_Surface *quaffle = NULL;

int Running = TRUE;
int keypressed=FALSE;
int mouseclicked=FALSE;
int oldX, oldY, oldAngle,lives;
double velocity = SPEED;
int harryStill = TRUE;
long KeyState[MAX_KEY];
double shootTime = 0;


typedef struct sprite{
   SDL_Surface *Img;
} SPRITE;

typedef struct object 
{ 
	int index;
   	SDL_Surface *Img;
   	int X,Y,W,H,DIRX,DIRY,Life;
   	float FX,FY,DX,DY;
   	int Angle;
	struct object *next;
} OBJECT;



OBJECT harry;
OBJECT *Quaffle;
