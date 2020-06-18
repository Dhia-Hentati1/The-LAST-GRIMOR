#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include"game.h"
#include"play.h"
#include"play2.h"
#include"play3.h"
#include"settings2.h"
#include"credits.h"
#include"menu.h"
#include"menu2.h"
#include"menu3.h"
#include"quiz.h"
#include"exit.h"
#include"navg.h"
#include"savemenu.h"
#include "enigme.h"
#include "coin.h"
#include <time.h>

int main() {
SDL_Rect poskey,poskey1,poskey2,poskey3,poskey4;

	SDL_Init(SDL_INIT_EVERYTHING);

	TTF_Init();
	int nb = 0 ;
	Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
    Enigme e ;
	Game game;
	GAME_Init(&game);
	   srand(time(NULL));

    coin c,c1,c2,c3,c4;
poskey.x=475;	
poskey1.x=550;	
poskey2.x=625;		
poskey3.x=700;
poskey.y=330;	
poskey1.y=320;	
poskey2.y=320;		
poskey3.y=330;
init_coin(&c,poskey.x,poskey.y);
init_coin(&c1,poskey1.x,poskey1.y);
init_coin(&c2,poskey2.x,poskey2.y);
init_coin(&c3,poskey3.x,poskey3.y);
init_coin(&c4,poskey4.x,poskey4.y);
	Quiz quiz;
	QUIZ_Init(&quiz,"questions.txt");

	Play play;
	PLAY_Init(&play);
	Play2 play2;
	PLAY2_Init(&play2);
	Play3 play3;
	PLAY3_Init(&play3);


	Menu m;

	MENU_Init(&m, &game.screen);
	ENIGME_Init(&e ,&game.screen) ;

	Menu2 m2;
	MENU2_Init(&m2, &game.screen);

	Menu3 menu3;
	MENU3_Init(&menu3, &game.screen);

	Settings settings;
	SETTINGS_Init(&settings,&game.screen);

	Credits credits;
	CREDITS_Init(&credits);

	Navg navg;
	NAVG_Init(&navg,&game.screen);

	Exit exit ;
	EXIT_Init(&exit,&game.screen);

	Savem save;
	Savem_Init(&save,&game.screen);

	SDL_Event event;

	while(game.running){
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT){
				game.running = 0;
			}
			if(m2.enabled){
				MENU2_HandleEvent(&m2,&menu3,&event);
			}
			else if(menu3.enabled){
				MENU3_HandleEvent(&menu3,&play,&event);
			}
			else if(quiz.enabled){
				//QUIZ_HandleEvent(&quiz,&play.enabled,&play2.enabled,&play3.enabled,&event);
				//	nb = random_nbr(nb) ;
                ENIGME_Render(&e , &game.screen,nb,&event) ;
			}

			else if(play3.enabled)
				PLAY3_HandleEvent(&play3, &exit,&save ,&event);
			else if(play2.enabled)
				PLAY2_HandleEvent(&play2,&save,&event);
			else if(play.enabled)
				PLAY_HandleEvent(&play,&quiz,&save,&event);
			else if(navg.enabled)
				NAVG_HandleEvent(&navg,&event);
			else if(settings.enabled)
				SETTINGS_HandleEvent(&settings,&navg,&event);
			else if(exit.enabled)
				EXIT_HandleEvent(&exit,&game,&event);
			else if(save.enabled)
				Savem_HandleEvent(&save,&game,&event);
			else if(credits.enabled)
				CREDITS_HandleEvent(&credits,&event);

			else
				MENU_HandleEvent(&m,&m2,&game,&settings,&play,&credits,&exit,&event);
		} //pollevent

		if(m2.enabled)
			MENU2_Render(&m2);
		else if(menu3.enabled)
			MENU3_Render(&menu3);
		 else if(save.enabled)
			Savem_Render(&save);
		else if(quiz.enabled)
		{
    //        nb = random_nbr(nb) ;
      //   ENIGME_Render(&e , &game.screen,nb,&event) ;
			//QUIZ_Render(&quiz,&game.screen);
        }
		else if(play3.enabled)
			PLAY3_Render(&play3,&quiz,&game.screen);
		else if(play2.enabled)
			PLAY2_Render(&play2,&quiz,&game.screen);
		else if(play.enabled)
			PLAY_Render(&play,&play2,&play3,&quiz,&c,&game.screen);
		else if(navg.enabled)
			NAVG_Render(&navg);
		else if(settings.enabled)
			SETTINGS_Render(&settings);
		else if(exit.enabled)
			EXIT_Render(&exit);

		else if(credits.enabled)
			CREDITS_Render(&credits,&game.screen);

		else if(m.enabled)
			MENU_Render(&m);
		if(play.player.vie.hp <= 0){
			PLAY_Init(&play);
			PLAY2_Init(&play2);
			PLAY3_Init(&play3);

		}
		if(play2.player.vie.hp <= 0){
			PLAY_Init(&play);
			PLAY2_Init(&play2);
			PLAY3_Init(&play3);

		}
		if(play3.player.vie.hp <= 0){
			PLAY_Init(&play);
			PLAY2_Init(&play2);
			PLAY3_Init(&play3);

		}


		SDL_Flip(game.screen);
		SDL_Delay(16);
	}
	SDL_FreeSurface(game.screen);

	SDL_Quit();
}

