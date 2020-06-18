#include <stdio.h>
#include <stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include"clochard.h"
#include"vie.h"
#include"play.h"
#include"objet.h"
#include"savemenu.h"
#include "coin.h"
#include <SDL/SDL_mixer.h>
#include"game.h"
Objet tayara;
Game game;
void PLAY_Init(Play *play){
	
        play->enabled = 0;
	play->restart = 0;
	play->bg = IMG_Load("map.png");
	play->sx = 0;

	CLOCHARD_Init(&play->clochard,1000,350);
	CLOCHARD_Init(&play->clochard2,2900,350);
	CLOCHARD_Init(&play->clochard3,4500,350);
	PLAYER_Init(&play->player);
	OBJET_Init(&play->o,500,350,"BOOM.png");
	OBJET_Init(&play->o1,2100,720-129,"BOOM.png");
	OBJET_Init(&play->o2,4800,720-155,"KHOBEZ.png");
	OBJET_Init(&play->o3,3600,720-154,"VIE+.png");
	OBJET_Init(&play->o4,5500,720-96,"KHODHRA1.png");
	OBJET_Init(&play->o5,5780,720-89,"KHODHRA2.png");
OBJET_Init(&tayara,5800,30,"tayara.png");
       
	//extraire("save.txt",&(play->sx), &(play->player.position.x) );
}

void PLAY_WrongAnswer(Play *play, Play2 *play2) {
	PLAY_Init(play);
	play2->enabled = 0;
}

void PLAY_Render(Play *play, Play2 *play2,Play3 *play3,Quiz *quiz,coin *c, SDL_Surface **screen){      coin cc,c1,c2,c3,c4;
               SDL_Rect poskey,poskey1,poskey2,poskey3,poskey4;
		Mix_Chunk *son ,*son2,*son3,*son4;
       int running=0;
	SDL_Event event;
         int tempsPrecedent= 0;
        int TEMPS=10;
		son = Mix_LoadWAV("scream.wav");
		son2 = Mix_LoadWAV("exp.wav");
		son3 = Mix_LoadWAV("yahoo.wav");
		son4 = Mix_LoadWAV("burp.wav");
	SDL_Rect r = {play->sx,0,800,600};
	SDL_BlitSurface(play->bg,&r,*screen,NULL);
	play->sx = play->player.position.x-(800/2);
	if(play->sx < 0)
		play->sx = 0;
	if(play->sx >= 7560 - 800){
		play->sx = 7560 - 800;
	}
	if(play->player.position.x>=7400)
	{
		play->player.position.x=7400;
		}
	 if(play->player.position.x<=0)
		{
			play->player.position.x=0;
			}

SDL_Rect rc = {play->clochard.x, play->clochard.y,100,128};
	SDL_Rect rp = {play->player.position.x, play->player.position.y,110,210};


	CLOCHARD_Render(&play->clochard,r,screen);
	CLOCHARD_Render(&play->clochard2,r,screen);
	CLOCHARD_Render(&play->clochard3,r,screen);
	PLAYER_Render(&play->player,r,screen);
	OBJET_Render(&play->o,r,screen);
	OBJET_Render(&play->o1,r,screen);
	OBJET_Render(&play->o2,r,screen);
	OBJET_Render(&play->o3,r,screen);
	OBJET_Render(&play->o4,r,screen);
	OBJET_Render(&play->o5,r,screen);
	OBJET_Render(&tayara,r,screen);
/*init_coin(&c,poskey.x,poskey.y);
init_coin(&c1,poskey1.x,poskey1.y);
init_coin(&c2,poskey2.x,poskey2.y);
init_coin(&c3,poskey3.x,poskey3.y);
init_coin(&c4,poskey4.x,poskey4.y);

poskey.x=475;	
poskey1.x=550;	
poskey2.x=625;		
poskey3.x=700;
poskey.y=330;	
poskey1.y=320;	
poskey2.y=320;		
poskey3.y=330;
*/
while(running)
{
	while(SDL_PollEvent(&event))
	{
	play->player.time.time=SDL_GetTicks();
	if (play->player.time.time - tempsPrecedent > TEMPS)
	{
	tempsPrecedent = play->player.time.time;
	}
}
SDL_Rect relcoord2={475,330};
SDL_Rect relcoord3={550,320};			
SDL_Rect relcoord4={625,320};			
SDL_Rect relcoord5={700,330};	

SDL_BlitSurface(c->tab[c->frame],NULL,*screen,&relcoord2);
SDL_BlitSurface(c->tab[c->frame],NULL,*screen,&relcoord3);
SDL_BlitSurface(c->tab[c->frame],NULL,*screen,&relcoord4);
SDL_BlitSurface(c->tab[c->frame],NULL,*screen,&relcoord5);
//animer_coin(&c);
animer_coin(&c1);
animer_coin(&c2);
animer_coin(&c3);
animer_coin(&c4);

if (collision(rp,relcoord2))
{
VIE_AjouterHp(&play->player.vie, 100);
poskey.x=9000;
}
if (collision(rp,relcoord3))
{
VIE_AjouterHp(&play->player.vie, 100);
poskey1.x=9000;

}
if (collision(rp,relcoord4))
{
VIE_AjouterHp(&play->player.vie, 100);
poskey2.x=9000;
}
if (collision(rp,relcoord4))
{
VIE_AjouterHp(&play->player.vie, 100);	
poskey3.x=9000;
}
if (collision(rp,relcoord5))
{
VIE_AjouterHp(&play->player.vie, 100);
poskey4.x=9000;
}

//SDL_Delay(0.5);
SDL_Flip(*screen);
SDL_Delay(10);


}

	
	if(collision(rp,rc)){

		VIE_ReduireHp(&play->player.vie,1);
		if(play->clochard.x >= play->player.position.x){
		play->player.position.x -=5;
			}
		else {
			play->player.position.x +=5;
			}

		Mix_PlayChannel(1, son, 0);
	}
	SDL_Rect rc2 = {play->clochard2.x, play->clochard2.y,100,128};
	if(collision(rp,rc2)){
		VIE_ReduireHp(&play->player.vie,1);
		if(play->clochard2.x >= play->player.position.x){
		play->player.position.x -=5;
			}
		else {
			play->player.position.x +=5;
			}

		Mix_PlayChannel(1, son, 0);

	}

	SDL_Rect rc3 = {play->clochard3.x, play->clochard3.y,100,128};
	if(collision(rp,rc3)){
		VIE_ReduireHp(&play->player.vie,1);
		if(play->clochard3.x >= play->player.position.x){
		play->player.position.x -=5;
			}
		else {
			play->player.position.x +=5;
			}

		Mix_PlayChannel(1, son, 0);
	}

	SDL_Rect ro = {play->o.x,play->o.y,play->o.sprite->w,play->o.sprite->h};
	if(collision(rp,ro)){
			//Mix_PlayChannel(1, son2, 0);
			play->player.position.y = ro.y-rp.h-2;
			if(play->o.sprite->h == 129){
				Mix_PlayChannel(1, son2, 0);
				VIE_ReduireHp(&play->player.vie,100);
				play->o.sprite = IMG_Load("box.png");
				play->o.y += 42;

			}
	}

	SDL_Rect ro1 = {play->o1.x,play->o1.y,play->o1.sprite->w,play->o1.sprite->h};
	if(collision(rp,ro1)){
			//Mix_PlayChannel(1, son2, 0);
			play->player.position.y = ro1.y-rp.h-2;
			if(play->o1.sprite->h == 129){
				Mix_PlayChannel(1, son2, 0);
				VIE_ReduireHp(&play->player.vie,100);
				play->o1.sprite = IMG_Load("box.png");
				play->o1.y =633;

			}
	}

	SDL_Rect ro2 = {play->o2.x,play->o2.y,play->o2.sprite->w,play->o2.sprite->h};
	if(collision(rp,ro2)){
			if(play->o2.sprite->h == 155){
				play->o2.sprite=IMG_Load("box.png");
				play->o2.y =635;
				VIE_AjouterHp(&play->player.vie, 30);
			}
			play->player.position.y = ro2.y-rp.h-2;
				Mix_PlayChannel(1, son4, 0);
	}

	SDL_Rect ro3 = {play->o3.x,play->o3.y,play->o3.sprite->w,play->o3.sprite->h};
	if(collision(rp,ro3)){
			if(play->o3.sprite->h == 154){
				play->o3.sprite = IMG_Load("box.png");
				play->o3.y =634;
				VIE_AjouterHp(&play->player.vie, 1000);
			}
			play->player.position.y = ro3.y-rp.h-2;
			Mix_PlayChannel(1, son3, 0);
	}
SDL_Rect ro4 = {play->o4.x,play->o4.y,play->o4.sprite->w,play->o4.sprite->h};
	if(collision(rp,ro4)){
	
		play->player.position.y = ro4.y-rp.h-2	;
	}
SDL_Rect ro5 = {play->o5.x,play->o5.y,play->o5.sprite->w,play->o5.sprite->h};
	if(collision(rp,ro5)){
		
		play->player.position.y = ro5.y-rp.h-2;
	}


	SDL_Rect r_tayara = {tayara.x+500,tayara.y,10,tayara.sprite->h};
	if(collision(rp,r_tayara)){
		play->player.position.x += 100;
		play->player.vx = 0;
		play2->enabled = 1;
		QUIZ_NextQuestion(quiz);
		quiz->enabled = 1;
	}

	SDL_Rect rend = {play->bg->w - 100, 0,100,768};
	if(collision(rp,rend)){

		play->enabled = 0;
		play2->enabled=0;
		play3->enabled = 1;
		QUIZ_Init(quiz,"questions3.txt");
		QUIZ_NextQuestion(quiz);
		quiz->enabled = 1;

	}


	if(play->restart) {
		PLAY_Init(play);
		play->enabled = 1;
		play2->enabled = 0;
	}
}


void PLAY_HandleEvent(Play *play,Quiz *quiz,Savem *save, SDL_Event* event){
Mix_Chunk *son;
son = Mix_LoadWAV("yahoo.wav");

	if(event->type == SDL_KEYDOWN){
		if(event->key.keysym.sym==SDLK_q) {
			QUIZ_NextQuestion(quiz);
			quiz->enabled = 1;
		}
		if(event->key.keysym.sym==SDLK_RIGHT)
			play->player.vx = 15;
		if(event->key.keysym.sym==SDLK_LEFT){
			if(play->player.position.x < 6500)
				play->player.vx = -15;
		}
		if(event->key.keysym.sym==SDLK_UP){

			if(play->player.position.y==260){
			Mix_PlayChannel(1, son, 0);
			play->player.vy = -20;
				}

			}
		if(event->key.keysym.sym==SDLK_DOWN)
			VIE_ReduireHp(&play->player.vie,10);
		if(event->key.keysym.sym == SDLK_ESCAPE){

			play->enabled = 0;
			save->enabled= 1;}
	}
	if(event->type == SDL_KEYUP){
		if(event->key.keysym.sym==SDLK_RIGHT)
			play->player.vx = 0;
		if(event->key.keysym.sym==SDLK_LEFT)
			play->player.vx = 0;
		if(event->key.keysym.sym == SDLK_ESCAPE){
			//fichier("save.txt",&(play->sx), &(play->player.position.x) , &play->enabled);
			play->enabled = 1;
			save->enabled= 0;
		}
	}
}
