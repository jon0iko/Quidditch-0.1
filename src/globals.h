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
#define MAX_KEY 1000
#define PI 3.14159265

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Surface *background = NULL;
SDL_Surface *quaffle = NULL;
SDL_Surface *bludger = NULL;
SDL_Surface *MenuBG = NULL;
SDL_Surface *hoop = NULL;
SDL_Surface *snitch = NULL;
SDL_Surface *snitch2 = NULL;
SDL_Surface *gOver = NULL;
SDL_Surface *settingsbg = NULL;
Mix_Music *gameMusic = NULL, *introMusic = NULL;
Mix_Chunk *bludgerHit, *bludgerCollision, *click, *endgame, *hoopScore, *snitchCaught, *throw;

int Running = TRUE;
int sdrawn = FALSE;
int keypressed = FALSE;
int mouseclicked = FALSE;
int mouseX, mouseY;
int oldX, oldY, oldAngle;
double velocity = SPEED;
int harryStill = TRUE;
long KeyState[MAX_KEY];
double shootTime = 0;
int collisionFlag = FALSE;
unsigned int collisionTimer = 0;
int timeFlag = FALSE;
unsigned int minutes, seconds, countdown = 120000, timeElapsed = 0, remainingTime, timerTime;
int t = 100;
int upflag = 1, downflag = 1;
int score = 0, prevScore = 0;
int snitchFlag = FALSE, drawSnitch = TRUE, snitchTimer = 0;
int frame = 0;
int snitchAnimationSpeed = 10;
SDL_Surface *ibg = NULL;
SDL_Surface *leaderbd = NULL; 
int soundFlag = TRUE, volume = MIX_MAX_VOLUME;
int bestScore = 0;
int difficultyFlag = 0;



typedef struct sprite
{
	SDL_Surface *Img;
} SPRITE;

enum HOOPSTATE
{
	first,
	second,
	third,
	fourth,
	fifth,
	sixth,
	seventh,
	eighth
};
enum HOOPSTATE hoopState;

SPRITE hoopSprite[8];
SPRITE snitchSprite[2];

typedef struct object
{
	int index;
	SDL_Surface *Img;
	int X, Y, W, H, DIRX, DIRY, Life;
	float FX, FY, DX, DY;
	int Angle;
	struct object *next;
} OBJECT;

OBJECT harry;
OBJECT *Quaffle;
OBJECT *bludgers;
OBJECT *SNITCH;
OBJECT hoop1, box, clockk;