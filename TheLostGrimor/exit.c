#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include<string.h>
#include"game.h"
#include"exit.h"

void EXIT_Init(Exit *exit, SDL_Surface **screen){
	exit->screen = screen;
	exit->bg = IMG_Load("menu2.jpg");
	exit->font = TTF_OpenFont("theme.ttf",86);

	exit->rouge.r = 217;
	exit->rouge.g = 10;
	exit->rouge.b = 4;

	exit->gold.r = 251;
	exit->gold.g = 208;
	exit->gold.b = 119;	

	exit->noire.r = exit->noire.g = exit->noire.b = 0;
	exit->choixMenu = 0;
	exit->enabled = 0;
}

void EXIT_Render(Exit *exit){
	SDL_BlitSurface(exit->bg, NULL, *exit->screen, NULL);
        EXIT_RenderFont(exit,80,100,"Are you sure ?",exit->ex == 1);
	EXIT_RenderFont(exit,120,340,"YES",exit->choixMenu == 1);
	EXIT_RenderFont(exit,520,340,"NO", exit->choixMenu == 0);
	
}

void EXIT_RenderFont(Exit *exit, int x, int y, const char* text, int b){
	SDL_Rect r;
	r.x = x;
	r.y = y;
	exit->msg = TTF_RenderText_Solid(exit->font,text,exit->noire);
	SDL_BlitSurface(exit->msg,NULL,*exit->screen,&r);
	r.x -= 7;
	r.y += 7;
	if(!b)
		exit->msg = TTF_RenderText_Solid(exit->font,text,exit->rouge);
	else 
		exit->msg = TTF_RenderText_Solid(exit->font,text,exit->gold);
	SDL_BlitSurface(exit->msg,NULL,*exit->screen,&r);
}

void EXIT_HandleEvent(Exit *exit,Game *game,SDL_Event *event){
Mix_Chunk *son;
son = Mix_LoadWAV("bt3.wav");
			if(event->type == SDL_KEYDOWN){
				if(event->key.keysym.sym == SDLK_RIGHT){
					if(exit->choixMenu != 1){
						exit->choixMenu++;
						
						Mix_PlayChannel(1, son, 0);}
					else {
						exit->choixMenu = 0;
						Mix_PlayChannel(1, son, 0);}
				}
				if(event->key.keysym.sym == SDLK_LEFT){
					if(exit->choixMenu != 0){
						
						Mix_PlayChannel(1, son, 0);
						exit->choixMenu--;}
					else {
						exit->choixMenu = 1;
						Mix_PlayChannel(1, son, 0); }
				}

				if(event->key.keysym.sym == SDLK_RETURN){
					if(exit->choixMenu == 1){
						
						game->running=0;
					}
					if(exit->choixMenu == 0){
						exit->enabled = 0;
						
					}
				}
				if(event->key.keysym.sym == SDLK_ESCAPE){
					exit->enabled = 0;
				}
			}

}
