#include "../include/grille.h"
#include "../include/joueur.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

/**
* @file		joueur.c
* @author	Yanis Chibout
* @version 	1.0
* @date		avril 2015
* @brief 	fonction correspondant au joueur
*/

Grille posjoueur (Grille g1, joueur j1)
{
	g1.g[j1.posn][j1.posm] = 8;
	
	return g1;
}

Grille retiretrace (Grille g1, joueur j1)
{
	g1.g[j1.posn][j1.posm] = 0;
	
	return g1;
}
