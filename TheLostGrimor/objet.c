#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include"objet.h"


void OBJET_Init(Objet *c, int x, int y, const char* path){
	c->sprite = IMG_Load(path);
	c->x = x;
	c->y = y;
}

void OBJET_Render(Objet *c, SDL_Rect r, SDL_Surface **screen){
	SDL_Rect r2 = {c->x - r.x, c->y};
	SDL_BlitSurface(c->sprite,NULL,*screen, &r2);
}
