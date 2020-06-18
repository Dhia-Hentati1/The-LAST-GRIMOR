#pragma once
#include<SDL/SDL_ttf.h>

typedef struct Question {
	char question[255];
	char reponse1[255];
	char reponse2[255];
	char reponse3[255];
} Question;

typedef struct Quiz {
	SDL_Surface **screen, *bg, *msg;
	SDL_Color rouge,noire,gold;
	int enabled;
	Question questions[5];
	FILE *f;
	TTF_Font *font;
	int qid;
	int choices[3];
	int currentChoice;
} Quiz;

void QUIZ_Init(Quiz *s,const char* filename);
void QUIZ_Render(Quiz *s, SDL_Surface **screen);
void QUIZ_HandleEvent(Quiz *s,int *play_enabled, int *play2_enabled, int *play3_enabled, SDL_Event *event);
void QUIZ_NextQuestion(Quiz *s);
const char* QUIZ_GetQuestion(Question *t,int q);
