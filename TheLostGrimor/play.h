#pragma once
#include"player.h"
#include"clochard.h"
#include"boundingbox.h"
#include"play2.h"
#include"play3.h"
#include"quiz.h"
#include"objet.h"
#include"savemenu.h"
#include"coin.h"
typedef struct Play {
	SDL_Surface *bg,*bg2;
	int sx;
	int enabled;
	int restart;
	
	Clochard clochard,clochard2,clochard3;
	Player player;
	Objet o,o1,o2,o3,o4,o5;
} Play;

void PLAY_Init(Play *play );
void PLAY_Render(Play *play, Play2 *play2, Play3 *play3 ,Quiz *quiz,coin *c, SDL_Surface **screen);
void PLAY_HandleEvent(Play *play,Quiz *quiz,Savem *save,SDL_Event *event);
void PLAY_WrongAnswer(Play *play, Play2 *play2);
