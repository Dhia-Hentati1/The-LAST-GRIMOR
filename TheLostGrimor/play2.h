#pragma once
#include"player.h"
#include"clochard.h"
#include"boundingbox.h"
#include"quiz.h"
#include"objet.h"
#include"savemenu.h"
#include"save.h"
typedef struct Play2 {
	SDL_Surface *bg,*bg2;
	int sx,sx2;
	int enabled;
	int restart;
	
	Clochard clochard,clochard2,clochard3;
	Player player;
Objet o,o1,o2,o3,o4,o5;
} Play2;

void PLAY2_Init(Play2 *play2);
void PLAY2_Render(Play2 *play2,Quiz *quiz, SDL_Surface **screen);
void PLAY2_HandleEvent(Play2 *play2,Savem *save,SDL_Event *event);
