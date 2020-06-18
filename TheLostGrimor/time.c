#include"time.h"

void initializerTemps(Time *time){
	time->font = TTF_OpenFont("arial.ttf", 32);

	sprintf(time->timeString,"Time| 00:00:00");
	sprintf(time->scoreString,"Score| 0000");
	SDL_Color color = {255,255,255};
	SDL_Color color2 = {255,255,255};
	time->msg = TTF_RenderText_Solid(time->font,time->timeString,color);
	time->txt = TTF_RenderText_Solid(time->font,time->scoreString,color);
}

void afficherTemps(Time *time, SDL_Surface **screen){
	SDL_Color color = {255,255,255};
	SDL_Color color2 = {255,208,119};
	SDL_Rect r,r1;
	r.x=25 + 225;
	r.y=10;
	r1.x= 25 + 25 + 225 + 225 + 35;
	r1.y=10;
	time->time+=100;
	time->score+=2;
	if(time->time % 60 == 0){
		sprintf(time->timeString,"Time| %02d:%02d:%02d\n",time->time/60/60/60,time->time/60/60,(time->time/60)%100);
		time->msg = TTF_RenderText_Solid(time->font,time->timeString,color);
		if((time->time /60/60 %5)==0)
		{

			sprintf(time->scoreString,"Score| %02d%02d\n",time->score/100,time->score%100);
		time->txt = TTF_RenderText_Solid(time->font,time->scoreString,color2);
	}}
	SDL_BlitSurface(time->msg,NULL,*screen,&r);
	SDL_BlitSurface(time->txt,NULL,*screen,&r1);
}
