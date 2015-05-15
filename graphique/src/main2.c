/**
* @file     main2.c
* @author   Yanis Chibout / Youssef Rizk
* @version  1.1
* @date     mai 2015
* @brief    fichier secondaire de tests pour l'interface graphique
*/


#include "../include/grille.h"
#include "../include/joueur.h"
#include <stdlib.h>
#include <stdio.h>
#include "SDL.h"
#include "SDL_image.h"

#define SCREEN_WIDTH  320
#define SCREEN_HEIGHT 288
#define SPRITE_SIZE    32
#define STEP_SIZE 32

int main(int argc, char* argv[])
{	
	Grille g1 = lirefichier(argv[1]);
	
	joueur j1; 
	
	j1.posn = 0; 
	j1.posm = 0;
	posjoueur(g1, j1);
		
	SDL_Surface *screen, *temp, *grass, *wall, *cloudu, *cloudd, *cloudl, *cloudr, *fire;
	SDL_Rect rcSprite, rcGrass;
	SDL_Event event;
	Uint8 *keystate;
	int colorkey, gameover;
	
	SDL_Init(SDL_INIT_VIDEO);
	
	SDL_WM_SetCaption("Jeu TecDev SDL", "Jeu TecDev SDL"); 
	
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0); 
	
	temp  = SDL_LoadBMP("fire.bmp"); 
	fire = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);
	
	temp  = SDL_LoadBMP("grass.bmp"); 
	grass = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);
	
	temp  = SDL_LoadBMP("cloudu.bmp"); 
	cloudu = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);
	
	temp  = SDL_LoadBMP("cloudd.bmp"); 
	cloudd = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);
	
	temp  = SDL_LoadBMP("cloudl.bmp");
	cloudl = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);
	
	temp  = SDL_LoadBMP("cloudr.bmp"); 
	cloudr = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);
	
	temp  = SDL_LoadBMP("wall.bmp");
	wall = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);
	
	colorkey = SDL_MapRGB(screen->format, 255, 255, 255); 
	SDL_SetColorKey(cloudu, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
				 
	colorkey = SDL_MapRGB(screen->format, 255, 255, 255); 
	SDL_SetColorKey(cloudd, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);			
				 
	colorkey = SDL_MapRGB(screen->format, 255, 255, 255); 
	SDL_SetColorKey(cloudl, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);			 
				 
	colorkey = SDL_MapRGB(screen->format, 255, 255, 255); 
	SDL_SetColorKey(cloudr, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);			 
	
	colorkey = SDL_MapRGB(screen->format, 255, 255, 255); 
	SDL_SetColorKey(wall, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
	
	colorkey = SDL_MapRGB(screen->format, 255, 255, 255); 
	SDL_SetColorKey(fire, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);

	rcSprite.x = 0; 
	rcSprite.y = 0;
	SDL_BlitSurface(cloudd, NULL, screen, &rcSprite);
	
	gameover = 0;
	
	while (!gameover)
	{
	 if (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				gameover = 1;
				break;
				
				case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
					case SDLK_ESCAPE:
					case SDLK_q:
						gameover = 1;
						break;
					case SDLK_p:
						while (event.key.keysym.sym != SDLK_p) 
						{
							rcSprite.x = rcSprite.x;
							rcSprite.y = rcSprite.y;
							SDL_BlitSurface(cloudl, NULL, screen, &rcSprite);
						}
						break;
					case SDLK_r:
						rcSprite.x = 0;
						rcSprite.y = 0;
						j1.posn = 0;
						j1.posm = 0;
						posjoueur(g1, j1);
						break;
					default:
						break;
				}
				break;
			}
		}
		
		int x, y;
		
		for (x = 0; x < SCREEN_WIDTH/SPRITE_SIZE; x++)
		{
			for (y = 0; y < SCREEN_HEIGHT/SPRITE_SIZE; y++)
			{
				if (g1.g[y][x] == 0 || g1.g[y][x] == 8)
				{
					rcGrass.x = x * SPRITE_SIZE; 
					rcGrass.y = y * SPRITE_SIZE;
					SDL_BlitSurface(grass, NULL, screen, &rcGrass); 
				}
				else if (g1.g[y][x] == 5) 
				{
					rcGrass.x = x * SPRITE_SIZE; 
					rcGrass.y = y * SPRITE_SIZE;
					SDL_BlitSurface(grass, NULL, screen, &rcGrass);
					SDL_BlitSurface(fire, NULL, screen, &rcGrass);
				}
				else if (g1.g[y][x] == 1) 
				{
					rcGrass.x = x * SPRITE_SIZE;
					rcGrass.y = y * SPRITE_SIZE;
					SDL_BlitSurface(wall, NULL, screen, &rcGrass); 
				}
			}
		}
		
		keystate = SDL_GetKeyState(NULL); 
		
		int tempn = j1.posn; 
		int tempm = j1.posm;
		
		if (keystate[SDLK_LEFT] ) 
		{ 
			if (j1.posm-1 >= 0) 
			{ 
				if (g1.g[j1.posn][j1.posm-1] == 0) 
				{
					j1.posm--; 
					g1 = posjoueur(g1, j1); 
					rcSprite.x -= STEP_SIZE; 
					retiretrace(g1, j1); 
					SDL_BlitSurface(cloudl, NULL, screen, &rcSprite); //Changement de sprite : on veut le personnage tourné vers la gauche 
				}
				else if (g1.g[j1.posn][j1.posm-1] == 5)
				{
					j1.posm--;
					g1 = posjoueur(g1, j1);
					rcSprite.x -= STEP_SIZE;
					retiretrace(g1, j1);
					SDL_BlitSurface(cloudl, NULL, screen, &rcSprite);
					gameover = 1;
				}
				else 
				{
					j1.posm = tempm; //Le joueur ne bouge pas (il rencontre un mur)
				}
			}
			else 
			{
				j1.posm = 0; //Le joueur ne bouge pas (il est en 0)
			}
		}
		if (keystate[SDLK_RIGHT] ) 
		{
			if (j1.posm+1 <= SCREEN_WIDTH/STEP_SIZE) //Si le joueur est tout en bas de l'écran
			{
				if (g1.g[j1.posn][j1.posm+1] == 0)
				{
					j1.posm++;
					g1 = posjoueur(g1, j1);
					rcSprite.x += STEP_SIZE;
					retiretrace(g1, j1);
					SDL_BlitSurface(cloudr, NULL, screen, &rcSprite);
				}
				else if (g1.g[j1.posn][j1.posm+1] == 5)
				{
					j1.posm++;
					g1 = posjoueur(g1, j1);
					rcSprite.x += STEP_SIZE;
					retiretrace(g1, j1);
					SDL_BlitSurface(cloudr, NULL, screen, &rcSprite);
					gameover = 1;
				}
				else
				{
					j1.posm = tempm;
				}
			}
			else 
			{
				j1.posm = SCREEN_WIDTH/STEP_SIZE; 
			}
		}
		if (keystate[SDLK_UP] ) 
		{
			if (j1.posn-1 >= 0)
			{
				if (g1.g[j1.posn - 1][j1.posm] == 0) 
				{
					j1.posn--;
					g1 = posjoueur(g1, j1);
					rcSprite.y -= STEP_SIZE;
					retiretrace(g1, j1);
					SDL_BlitSurface(cloudu, NULL, screen, &rcSprite);
				}
				else if (g1.g[j1.posn - 1][j1.posm] == 5)
				{
					j1.posn--;
					g1 = posjoueur(g1, j1);
					rcSprite.y -= STEP_SIZE;
					retiretrace(g1, j1);
					SDL_BlitSurface(cloudu, NULL, screen, &rcSprite);
					gameover = 1;
				else 
				{
					j1.posn = tempn;
				}
			}
			else 
			{
				j1.posn = 0;
			}
		}
		if (keystate[SDLK_DOWN] ) 
		{
			if (j1.posn+1 <= SCREEN_HEIGHT/STEP_SIZE) 
			{
				if (g1.g[j1.posn+1][j1.posm] == 0)
				{
					j1.posn++;
					g1 = posjoueur(g1, j1);
					rcSprite.y += STEP_SIZE;
					retiretrace(g1, j1);
					SDL_BlitSurface(cloudd, NULL, screen, &rcSprite);
				}
				else if (g1.g[j1.posn+1][j1.posm] == 5)
				{
					j1.posn++;
					g1 = posjoueur(g1, j1);
					rcSprite.y += STEP_SIZE;
					retiretrace(g1, j1);
					SDL_BlitSurface(cloudd, NULL, screen, &rcSprite);
					gameover = 1;
				}
				else 
				{
					j1.posn = tempn;
				}
			}
			else
			{
				j1.posn = SCREEN_HEIGHT/STEP_SIZE;
			}
		}
		
		
		SDL_UpdateRect(screen,0,0,0,0);
	}
	
	SDL_FreeSurface(cloudd);
	SDL_FreeSurface(cloudu);
	SDL_FreeSurface(cloudl);
	SDL_FreeSurface(cloudr);
	SDL_FreeSurface(fire);
	SDL_FreeSurface(grass);
	SDL_FreeSurface(wall);
	SDL_Quit();

	return 0;
}
