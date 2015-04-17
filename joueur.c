#include "grille.h"
#include "joueur.h"
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

joueur def_inventaire (joueur j1)
{
	int i;
	j1.inventaire = (char**) malloc (10 * sizeof(char*));
	
	for (i = 0; i < 10; i++)
	{
		j1.inventaire[i] ="------------------------";
	}

	return j1;
}

/*void affiche_inventaire (joueur j1)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		printw("%s\n", j1.inventaire[i]);
		refresh();
	}
} */

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

joueur deplacement (Grille g1, joueur j1)
{
	initscr();

	int a = getch();
	
	switch (a)
	{
		case 'z': clear();
				  if (g1.g[(j1.posn) - 1][j1.posm] == 1 || (j1.posn - 1) < 0)
				  {
					  clear();
					  afficheGrillew(g1);
					  refresh();
				  }
				  else
				  {
					  switch (g1.g[(j1.posn) - 1][j1.posm])
					  {
						  case 2 : j1.pv += 10;
								   break;
								   
						  case 3 : j1.atk += 3;
								   break;
								   
						  case 4 : j1.def += 3;
						  
						  default :  afficheGrillew(g1);
									 refresh();
					  }
					  clear();
					  retiretrace(g1, j1);
					  j1.posn --;
					  posjoueur(g1, j1);
					  afficheGrillew(g1);
					  refresh();
				  }
				  break;
					 
		case 'd': clear();
				  if (g1.g[j1.posn][(j1.posm) + 1] == 1 || (j1.posm + 1) > g1.m-1)
				  {
					  clear();
					  afficheGrillew(g1);
					  refresh();
				  }
				  else
				  {
					  switch (g1.g[j1.posn][(j1.posm) + 1])
					  {
						  case 2 : j1.pv += 10;
								   break;
								   
						  case 3 : j1.atk += 3;
								   break;
								   
						  case 4 : j1.def += 3;
						  
						  default :  afficheGrillew(g1);
									 refresh();
					  }
					  clear();
					  retiretrace(g1, j1);
					  j1.posm ++;
					  posjoueur(g1, j1);
					  afficheGrillew(g1);
					  refresh();
				  }
				  break;

		case 's': clear();
				  if (g1.g[(j1.posn) + 1][j1.posm] == 1 || (j1.posn + 1) > g1.n-1)
				  {
					  clear();
					  afficheGrillew(g1);
					  refresh();
				  }
				  else
				  {
					  switch (g1.g[(j1.posn) + 1][j1.posm])
					  {
						  case 2 : j1.pv += 10;
								   break;
								   
						  case 3 : j1.atk += 3;
								   break;
								   
						  case 4 : j1.def += 3;
						  
						  default :  afficheGrillew(g1);
									 refresh();
					  }
					  clear();
					  retiretrace(g1, j1);
					  j1.posn ++;
					  posjoueur(g1, j1);
					  afficheGrillew(g1);
					  refresh();
				  }
				  break;
				  
		case 'q': clear();
				  if (g1.g[j1.posn][(j1.posm) - 1] == 1 || (j1.posm - 1) < 0)
				  {
					  clear();
					  afficheGrillew(g1);
					  refresh();
				  }
				  else
				  {
					  switch (g1.g[j1.posn][(j1.posm) - 1])
					  {
						  case 2 : j1.pv += 10;
								   break;
								   
						  case 3 : j1.atk += 3;
								   break;
								   
						  case 4 : j1.def += 3;
						  
						  default :  afficheGrillew(g1);
									 refresh();
					  }
					  retiretrace(g1, j1);
					  j1.posm --;
					  clear();
					  posjoueur(g1, j1);
					  afficheGrillew(g1);
					  refresh();
				  }
				   break;
		
		default: clear();
				 afficheGrillew(g1);
				 refresh();
	}
	
	return j1;
}
				  
joueur type_salle (Grille g1, joueur j1)
{
	switch (g1.effect)
	{
		case 1 : j1.pv --;
				 break;
		
		case 2 : if (j1.pv >= j1.pvmax)
				 {
					 j1.pv = j1.pv;
				 }
				 else
				 {
					j1.pv ++;
				 }
				 break;
		
		default : ;
	}
	
	return j1;
}

int chemin_valide (joueur *chemin, Grille g1, int nbdeplacements)
{
	int i;
	int test = 0;
	
	for (i = 0; i < nbdeplacements; i++)
	{
		if (g1.g[chemin[i].posn][chemin[i].posm] == 1)
		{
			test = 1;
		}
	}
	
	if (test == 0)
	{
		printw("\nLe chemin est valide\n");
		refresh();
	}
	else
	{
		printw("\nLe chemin n'est pas valide\n");
		refresh();
	}

	return test;
}
