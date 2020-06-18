#include"vie.h"

void VIE_Init(Vie *v){
	v->hp = 200;
	v->r.x = 25;
	v->r.y = 15;
	v->r.w = 225;
	v->r.h = 30;

	v->bar = SDL_CreateRGBSurface(255,0,0,32,0,0,0,0);
	SDL_FillRect(v->bar, NULL, 0xff0000);
}

void VIE_ReduireHp(Vie *v, int degat){
	v->hp -= degat;
	v->r.w = v->hp;
}

void VIE_AjouterHp(Vie *v, int degat){
	v->hp += degat;
	if(v->hp > 200){
		v->hp = 200;
	}
	v->r.w = v->hp;
}

void VIE_Render(Vie *v, SDL_Surface **screen){
	SDL_BlitSurface(v->bar,&v->r,*screen,&v->r);
}
