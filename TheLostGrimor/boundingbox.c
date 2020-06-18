#include"boundingbox.h"

int collision(SDL_Rect a, SDL_Rect b){
	if(!(a.x > b.x+b.w || a.y > b.y+b.h || a.x+a.w < b.x || a.y+a.h < b.y)){
		return 1;
	}
	return 0;
}
