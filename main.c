#include "grille.h"
#include "joueur.h"
#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

/**
* @file     main.c
* @author   Yanis Chibout
* @version  1.0
* @date     avril 2015
* @brief    fichier principal (à executer avec un fichier de grille comme premier arg)
*/

int main(int argc, char **argv)
{
	initscr();

	Grille g1 = lirefichier(argv[1]); //on lit le fichier mis en premier argument
	
	joueur j1; //définition d'un joueur
	j1.posn = g1.n / 2; //position de base en y
	j1.posm = g1.m / 2; //position de base en x
	
	j1.pv = 10;
	j1.atk = 3;
	j1.def = 2;
	j1.pvmax = 50;
	
	g1 = posjoueur(g1, j1); //placement du joueur dans la grille chargée

	def_inventaire(j1); //on initialise un inventaire
	
	afficheGrillew(g1); //affichage de base de la grille
	refresh();
	
	while(1)
	{
		if (j1.pv == 0) //Exemple : salles faisant des dégats
		{
			clear();
			printw("Game Over");
			refresh();
			getch();
			endwin();
			exit(1);
		}
		
		printw("\nPV : %d", j1.pv);
		printw("\nAttack : %d", j1.atk);
		printw("\nDefence : %d", j1.def);
		printw("\nInventaire : \n");
		j1 = deplacement(g1, j1); //Déplacement => En attente d'une touche
		j1 = type_salle(g1, j1); //Effet permanent de la salle
	}

	printf("\n Il y a %d cases non vides\n\n", nbcasesnonvides(g1));
}
