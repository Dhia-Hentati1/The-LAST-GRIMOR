#pragma once

typedef struct Clochard {
	SDL_Surface *sprite,*sprite2;
	int x,y;
	int dx,cx;
	SDL_Rect clips[7];
	SDL_Rect clips2[7];
	float frame;
	int time;
} Clochard;

void CLOCHARD_Init(Clochard *c, int x, int y);
void CLOCHARD_Render(Clochard *c, SDL_Rect r, SDL_Surface **screen);

