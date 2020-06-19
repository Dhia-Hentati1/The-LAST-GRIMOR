#pragma once
#include"vie.h" 
#include"time.h" 

typedef struct Player{

	int x,y,vx,vy;
	SDL_Surface **screen,*image, *image2;
	SDL_Rect position;
	SDL_Rect clips[9];
	SDL_Rect clips2[9];
	float frame;
	Time time;
	Vie vie;
} Player;

void PLAYER_Init(Player *p);
void PLAYER_Render(Player *p,SDL_Rect r, SDL_Surface **screen);
