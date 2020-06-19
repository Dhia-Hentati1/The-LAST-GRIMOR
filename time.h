#pragma once
#include<SDL/SDL.h>
#include<SDL/SDL_ttf.h>


typedef struct Time {
	SDL_Surface *msg,*txt;
	TTF_Font *font;
	int time,score;
	SDL_Rect r;
	char timeString[10],scoreString[10];

} Time;

void initializerTemps(Time *time);
void afficherTemps(Time *time,SDL_Surface **screen);
