#include "grille.h"
#include "joueur.h"
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
	Grille g1 = lirefichier(argv[1]); //Création d'une nouvelle grille à partir d'un fichier chargé
	
	//La grille servira de contrôleur mais l'utilisateur ne la voit jamais : il ne voit que l'interface graphique qui en découlera
	
	joueur j1; //Création d'un nouveau joueur
	j1.posn = 0; 
	j1.posm = 0;
	posjoueur(g1, j1);
		
	SDL_Surface *screen, *temp, *sprite, *grass, *wall, *black; //Création de surfaces SDL
	SDL_Rect rcSprite, rcGrass;
	SDL_Event event;
	Uint8 *keystate;
	int colorkey, gameover;
	
	SDL_Init(SDL_INIT_VIDEO); //initialisation de la fenêtre
	
	SDL_WM_SetCaption("Jeu TecDev SDL", "Jeu TecDev SDL"); //Définission du titre de la fenêtre
	
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0); //Création de la fenêtre
	
	temp   = SDL_LoadBMP("mushroom.bmp"); //Chargement du sprite mushroom.bmp dans la surface sprite
	sprite = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);
	
	temp   = SDL_LoadBMP("black.bmp"); //Chargement du sprite black.bmp dans la surface sprite
	black = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);
	
	colorkey = SDL_MapRGB(screen->format, 255, 255, 255); //Création de la transparence du sprite
	SDL_SetColorKey(sprite, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey); 
	
	temp  = SDL_LoadBMP("grass.bmp"); //Chargement du background grass.bmp dans la surface grass
	grass = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);
				 
	temp  = SDL_LoadBMP("wall.bmp"); //Chargement de l'image wall.bmp dans la surface wall
	wall = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);
	
	colorkey = SDL_MapRGB(screen->format, 255, 255, 255); //Transparence du mur
	SDL_SetColorKey(wall, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);

	rcSprite.x = 0; //Le sprite est en (0,0) à la base
	rcSprite.y = 0;
	
	gameover = 0; //Si gameover à 1 => Fin du jeu
	
	while (!gameover)
	{
	 if (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				gameover = 1;
				break;
				
				case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
					case SDLK_ESCAPE: //Si la touche entrée est échap
					case SDLK_q: //ou q
						gameover = 1; //Alors quitter le jeu
						break;
					case SDLK_p: //Si la touche entrée est p
						while (event.key.keysym.sym != SDLK_p) { //Alors tant que la touche entrée n'est pas p
							rcSprite.x = rcSprite.x; //Le joueur ne bouge pas
							rcSprite.y = rcSprite.y;
						}
						break;
					case SDLK_r: //Si la touche entrée est r
						rcSprite.x = 0; //Réinitialisation du sprite en 0
						rcSprite.y = 0;
						j1.posn = 0; //Réinitialisation du joueur en 0
						j1.posm = 0;
						posjoueur(g1, j1); //Replacement du joueur dans la grille
						break;
					default:
						break;
				}
				break;
			}
		}
		
		//Traitement des cas ou l'utilisateur entre une touche fléchée
		
		keystate = SDL_GetKeyState(NULL); //L'utilisateur entre une touche qui sera contenue dans keystate
		
		int tempn = j1.posn;
		int tempm = j1.posm;
		
		if (keystate[SDLK_LEFT] ) 
		{ 
			if (j1.posm-1 >= 0) 
			{ 
				if (g1.g[j1.posn][j1.posm-1] == 0) 
				{
					j1.posm--;
					g1 = posjoueur(g1, j1); //Placement du joueur dans la grille aux cases correspondantes
					rcSprite.x -= STEP_SIZE;
					retiretrace(g1, j1); //Retire la présence précédente du joueur dans la grille
				}
				else 
				{
					j1.posm = tempm;
				}
			}
			else 
			{
				j1.posm = 0;
			}
		}
		if (keystate[SDLK_RIGHT] ) 
		{
			if (j1.posm+1 <= SCREEN_WIDTH/STEP_SIZE) 
			{
				if (g1.g[j1.posn][j1.posm+1] == 0)
				{
					j1.posm++;
					g1 = posjoueur(g1, j1);
					rcSprite.x += STEP_SIZE;
					retiretrace(g1, j1);
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
				}
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
		
		//Traitement des cas de collision avec les bords de l'écran
		
		/*if ( rcSprite.x < 0 ) {
			rcSprite.x = 0;
		}
		else if ( rcSprite.x > SCREEN_WIDTH-SPRITE_SIZE ) {
			rcSprite.x = SCREEN_WIDTH-SPRITE_SIZE;
		}
		if ( rcSprite.y < 0 ) {
			rcSprite.y = 0;
		}
		else if ( rcSprite.y > SCREEN_HEIGHT-SPRITE_SIZE ) {
			rcSprite.y = SCREEN_HEIGHT-SPRITE_SIZE;
		}*/
		
		// Placement des images en fonction de la grille => Création de l'aire de jeu
		
		int x, y;
		
		for (x = 0; x < SCREEN_WIDTH/SPRITE_SIZE; x++)
		{
			for (y = 0; y < SCREEN_HEIGHT/SPRITE_SIZE; y++)
			{
				if (g1.g[y][x] == 0 || g1.g[y][x] == 8)//Si a cet endroit de la grille c'est libre
				{
					rcGrass.x = x * SPRITE_SIZE; //Déplacement du "curseur" rcGrass à cet endroit
					rcGrass.y = y * SPRITE_SIZE;
					SDL_BlitSurface(grass, NULL, screen, &rcGrass); //Placement de l'image grass à cet endroit
				}
				else if (g1.g[y][x] == 1) // Si à cet endroit il ya un mur
				{
					rcGrass.x = x * SPRITE_SIZE;
					rcGrass.y = y * SPRITE_SIZE;
					SDL_BlitSurface(wall, NULL, screen, &rcGrass); //Placement de l'image wall à cet endroit
				}
			}
		}
		
		SDL_BlitSurface(sprite, NULL, screen, &rcSprite); //Placement de l'image sprite à l'endroit indiqué par les coordonnées de rcSprite
		SDL_UpdateRect(screen,0,0,0,0); //Rafraîchissement de l'écran
	}
	
	//Quand le jeu est quitté :
	SDL_FreeSurface(sprite);
	SDL_FreeSurface(grass);
	SDL_FreeSurface(wall);
	SDL_Quit();

	return 0;
}
