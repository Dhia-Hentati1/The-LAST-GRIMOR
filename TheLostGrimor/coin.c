#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_rotozoom.h>

#include "coin.h"


/*#define gravity 9.81;
#define GRAVITY_SPEED 0.6
#define MAX_FALL_SPEED 5
#define JUMP_HEIGHT 14.5
#define SPEED 0.5
#define MAX_SPEED 5
*/

void init_coin(coin *c,int x, int y)
{
	c->tab[0]=IMG_Load("coin1.png");
	c->tab[1]=IMG_Load("coin2.png");
	c->tab[2]=IMG_Load("coin3.png");
	c->tab[3]=IMG_Load("coin4.png");
	c->tab[4]=IMG_Load("coin5.png");
	c->tab[5]=IMG_Load("coin6.png");
	c->tab[6]=IMG_Load("coin7.png");
	c->tab[7]=IMG_Load("coin8.png");

	c->pos.x=x;
	c->pos.y=y;
	c->frame=0;
}

void animer_coin(coin *c)
{
	//SDL_Delay(40);
	if(c->frame==7)
		c->frame=0;
	else
		c->frame++;
/*SDL_Event event ;
SDL_Rect position,rect;
int continuer =1;
SDL_Surface* image_entite = NULL,*screen = NULL,*rotation = NULL;

    double angle = 0;
    double zoom = 1;
    int sens = 1;
    int tempsPrecedent = 0, tempsActuel = 0;
    int TEMPS=30;

    /*SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_NOPARACHUTE);
    screen = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE/*| SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Rotozoom", NULL);
    backg = IMG_Load("12.png");*/
    /*image_entite = IMG_Load("coin1.png");

    //SDL_BlitSurface(backg, NULL, screen,& position);
   // SDL_Flip(screen);


//OBJET_Init(&o,0,200);
//rotation_objet(o,&ecran,&backg,positionFond);
while(continuer)
{ SDL_PollEvent(&event);
 switch (event.type)
   { case SDL_QUIT :
 continuer =0;
break;}


tempsActuel = SDL_GetTicks();
        if (tempsActuel - tempsPrecedent > TEMPS)
        {
            angle += 2;

            tempsPrecedent = tempsActuel;
        }
        else
        {
            SDL_Delay(TEMPS - (tempsActuel - tempsPrecedent));
        }
      rotation = rotozoomSurface(image_entite, angle, zoom, 0);
       rect.x = event.button.x - rotation->w/2;

       rect.y = event.button.y - rotation->h/2;

       //SDL_BlitSurface(backg , NULL, screen, &position);
        SDL_BlitSurface(rotation , NULL, screen, &rect);
        SDL_FreeSurface(rotation);

        if(zoom >= 2){sens = 0;}
        else if(zoom <= 0.5)
             {
                 sens = 1;
             }

        if(sens == 0)
       {zoom -= 0.02;}
        else{zoom += 0.02;}
	
        SDL_Flip(screen);

}
SDL_FreeSurface(screen);
//SDL_FreeSurface(backg);
SDL_FreeSurface(image_entite);
SDL_Quit();*/
}

