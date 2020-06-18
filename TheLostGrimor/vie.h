#pragma once
#include<SDL/SDL.h>

typedef struct Vie {
	int hp;
	int score;
	SDL_Surface *bar, *msg;
	SDL_Rect r;
} Vie;

void VIE_Init(Vie *v);
void VIE_ReduireHp(Vie *v, int degat);
void VIE_AjouterHp(Vie *v, int degat);
void VIE_AjouterScore(Vie *v, int score);
void VIE_Render(Vie *v,SDL_Surface **screen);
void VIE_RenderFont(Vie *vie, int x, int y, const char* text);
