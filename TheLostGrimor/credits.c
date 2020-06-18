#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include"credits.h"

void CREDITS_Init(Credits *s){
	s->bg = IMG_Load("credits.png");
	s->enabled = 0;
}

void CREDITS_Render(Credits *s,SDL_Surface **screen){
	SDL_BlitSurface(s->bg,NULL,*screen,NULL);
}

void CREDITS_HandleEvent(Credits *s, SDL_Event *event){
	if(event->type == SDL_KEYDOWN){
		if(event->key.keysym.sym == SDLK_ESCAPE){
			s->enabled = 0;
		}
	}
}
