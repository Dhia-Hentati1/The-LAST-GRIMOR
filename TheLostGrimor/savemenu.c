#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include<string.h>
#include"game.h"
#include"play.h"
#include"savemenu.h"
#include"save.h"
void Savem_Init(Savem *save, SDL_Surface **screen){Play *play;
	save->screen = screen;
	save->bg = IMG_Load("save.png");
	save->font = TTF_OpenFont("theme.ttf",56);

	save->rouge.r = 217;
	save->rouge.g = 10;
	save->rouge.b = 4;

	save->gold.r = 251;
	save->gold.g = 208;
	save->gold.b = 119;	

	save->noire.r = save->noire.g = save->noire.b = 0;
	save->choixMenu = 0;
	//extraire("save.txt",&(play->sx), &(play->player.position.x) );
	save->enabled = 0;
}

void Savem_Render(Savem *save){
	SDL_Rect r;
	r.x=150;
	r.y=50;
	SDL_BlitSurface(save->bg, NULL, *save->screen, &r);

	Savem_RenderFont(save,280,340,"YES",save->choixMenu == 1);
	Savem_RenderFont(save,450,340,"NO", save->choixMenu == 0);
	
}

void Savem_RenderFont(Savem *save, int x, int y, const char* text, int b){
	SDL_Rect r;
	r.x = x;
	r.y = y;
	save->msg = TTF_RenderText_Solid(save->font,text,save->noire);
	SDL_BlitSurface(save->msg,NULL,*save->screen,&r);
	r.x -= 7;
	r.y += 7;
	if(!b)
		save->msg = TTF_RenderText_Solid(save->font,text,save->rouge);
	else 
		save->msg = TTF_RenderText_Solid(save->font,text,save->gold);
	SDL_BlitSurface(save->msg,NULL,*save->screen,&r);
}

void Savem_HandleEvent(Savem *save,Game *game,SDL_Event *event){
Mix_Chunk *son;
Play *play;
son = Mix_LoadWAV("bt3.wav");
			if(event->type == SDL_KEYDOWN){
				if(event->key.keysym.sym == SDLK_RIGHT){
					if(save->choixMenu != 1){
						save->choixMenu++;
						
						Mix_PlayChannel(1, son, 0);}
					else {
						save->choixMenu = 0;
						Mix_PlayChannel(1, son, 0);}
				}
				if(event->key.keysym.sym == SDLK_LEFT){
					if(save->choixMenu != 0){
						
						Mix_PlayChannel(1, son, 0);
						save->choixMenu--;}
					else {
						save->choixMenu = 1;
						Mix_PlayChannel(1, son, 0); }
				}

				if(event->key.keysym.sym == SDLK_RETURN){
					if(save->choixMenu == 1){
						fichier("save.txt",&(play->sx), &(play->player.position.x) , &save->enabled);
						save->enabled=0;
					}
					if(save->choixMenu == 0){
						save->enabled = 0;
						
					}
				}
				if(event->key.keysym.sym == SDLK_ESCAPE){
					save->enabled=0;
				}
			}

}
