#pragma once
#include"player.h"
#include"clochard.h"
#include"boundingbox.h"
#include"savemenu.h"
#include"quiz.h"
#include"objet.h"
#include"game.h"
#include"exit.h"
#include"save.h"

typedef struct Play3 {
	SDL_Surface *bg;
	int sx;
	int enabled;
	int restart;
	
	Clochard clochard,clochard2,clochard3;
	Player player;
Objet o,o1,o2,o3,o4,o5;
} Play3;

void PLAY3_Init(Play3 *play3);
void PLAY3_Render(Play3 *play3,Quiz *quiz, SDL_Surface **screen);
void PLAY3_HandleEvent(Play3 *play3,Exit *exit,Savem *save,SDL_Event *event);
