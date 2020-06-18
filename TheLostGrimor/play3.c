#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include"clochard.h"
#include"vie.h"
#include"play2.h"
#include"play3.h"
#include"objet.h"
#include"quiz.h"
#include <SDL/SDL_mixer.h>
#include"game.h"
#include"exit.h"
#include"savemenu.h"



void PLAY3_Init(Play3 *play3){
	play3->enabled = 0;
	play3->restart = 0;
	play3->bg = IMG_Load("map_j.png");
	play3->sx = 0;

	CLOCHARD_Init(&play3->clochard,1200,720-128);
	CLOCHARD_Init(&play3->clochard2,2500,720-128);
	extraire("save.txt",&(play3->sx), &(play3->player.position.x) );
	PLAYER_Init(&play3->player);
	OBJET_Init(&play3->o,700,720-129,"BOOM.png");
	OBJET_Init(&play3->o1,2000,720-154,"VIE+.png");
	
	
}




void PLAY3_Render(Play3 *play3,Quiz *quiz, SDL_Surface **screen){
		Mix_Chunk *son,*son2,*son3;
		son2 = Mix_LoadWAV("exp.wav");
		son = Mix_LoadWAV("scream.wav");
		son3 = Mix_LoadWAV("yahoo.wav");
	SDL_Rect r = {play3->sx,0,1366,768};
	SDL_BlitSurface(play3->bg,&r,*screen,NULL);
	play3->sx = play3->player.position.x-(1366/2);
	if(play3->sx < 0)
		play3->sx = 0;
	if(play3->sx >= 3548 - 1366){
		play3->sx = 3548 - 1366;
	}
	if(play3->player.position.x>=3400)
	{
		play3->player.position.x=3400;
		}
	 if(play3->player.position.x<=0)
		{
			play3->player.position.x=0;
			}
	

	

	CLOCHARD_Render(&play3->clochard,r,screen);
	CLOCHARD_Render(&play3->clochard2,r,screen);
	
	PLAYER_Render(&play3->player,r,screen);
	OBJET_Render(&play3->o,r,screen);
	OBJET_Render(&play3->o1,r,screen);
	
	

	SDL_Rect rc = {play3->clochard.x, play3->clochard.y,112,128};
	SDL_Rect rp = {play3->player.position.x, play3->player.position.y,110,210};
	if(collision(rp,rc)){
         	
		VIE_ReduireHp(&play3->player.vie,1);
		if(play3->clochard.x >= play3->player.position.x){
		play3->player.position.x -=5;
			}
		else {
			play3->player.position.x +=5;
			}
		
		Mix_PlayChannel(1, son, 0);
	}
	SDL_Rect rc2 = {play3->clochard2.x, play3->clochard2.y,112,128};
	if(collision(rp,rc2)){
		VIE_ReduireHp(&play3->player.vie,1);
		if(play3->clochard2.x >= play3->player.position.x){
		play3->player.position.x -=5;
			}
		else {
			play3->player.position.x +=5;
			}
		
		Mix_PlayChannel(1, son, 0);

	}


	SDL_Rect ro = {play3->o.x,play3->o.y,129,play3->o.sprite->h};
	if(collision(rp,ro)){
			
			play3->player.position.y = ro.y-rp.h-2;
			if(play3->o.sprite->h == 129){
				Mix_PlayChannel(1, son2, 0);
				VIE_ReduireHp(&play3->player.vie,50);
				play3->o.sprite = IMG_Load("box.png");
				play3->o.y =633;
			}
	}

	SDL_Rect ro1 = {play3->o1.x,play3->o1.y,129,play3->o1.sprite->h};
	if(collision(rp,ro1)){
			play3->player.position.y = ro1.y-rp.h-2;
			if(play3->o1.sprite->h == 154){
				Mix_PlayChannel(1, son3, 0);
				VIE_AjouterHp(&play3->player.vie, 1000);
				play3->o1.sprite = IMG_Load("box.png");
				play3->o1.y =634;
			}
	}
	
		SDL_Rect rend = {play3->bg->w - 100, 0,100,768};
	
	if(collision(rp,rend)){
		play3->enabled = 0;
		
		QUIZ_Init(quiz,"questions.txt");
		QUIZ_NextQuestion(quiz);
		quiz->enabled = 1;
	}

		/*SDL_Rect rend2 = {play3->bg->w/2, 0,100,play3->bg->h};
	
	if(collision(rp,rend2)){
		play3->player.position.x += 100;
		play3->player.vx = 0;
		//play4->enabled = 1;
		QUIZ_NextQuestion(quiz);
		quiz->enabled = 1;
		
	}*/

	if(play3->restart) {
		PLAY3_Init(play3);
		play3->enabled = 1;
		//play4->enabled = 0;
	}
}

void PLAY3_HandleEvent(Play3 *play3,Exit *exit,Savem *save ,SDL_Event* event){
Mix_Chunk *son;
son = Mix_LoadWAV("yahoo.wav");
	if(event->type == SDL_KEYDOWN){
		if(event->key.keysym.sym==SDLK_RIGHT)
			play3->player.vx = 15;
		if(event->key.keysym.sym==SDLK_LEFT)
			play3->player.vx = -15;
		if(event->key.keysym.sym==SDLK_UP){
			if(play3->player.position.y==510){
				play3->player.vy = -24;
				Mix_PlayChannel(1, son, 0);}
}
		if(event->key.keysym.sym==SDLK_DOWN){
			VIE_ReduireHp(&play3->player.vie,10);}
		if(event->key.keysym.sym == SDLK_ESCAPE){
			VIE_ReduireHp(&play3->player.vie,100);		
			play3->enabled = 0;
			save->enabled= 1;
			//exit->enabled = 1;
			//game->running=0;
			}


		
	}
	if(event->type == SDL_KEYUP){
		if(event->key.keysym.sym==SDLK_RIGHT)
			play3->player.vx = 0;
		if(event->key.keysym.sym==SDLK_LEFT)
			play3->player.vx = 0;

	}
}
