#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "save.h"
void fichier(char nomfichier[],int *n,  short int *i  , int *running)
{
FILE*f=NULL;

f=fopen(nomfichier,"w+");

                    if ((f != NULL )||(*running==0))
        {
            fprintf(f,"%d ; %d\n",*n,*i);
             
            
        }
fclose(f);
        }
 void extraire(char nomfichier[],int *x, short int *y ) 
 {
 FILE*f=NULL;

f=fopen(nomfichier,"r");
if(f!=NULL)
{
fscanf(f,"%d ; %hd", x , y ) ; 

} 
fclose(f);
 }
