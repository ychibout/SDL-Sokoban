#include "grille.h"
#include "joueur.h"
#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

int main(int argc, char **argv)
{
	initscr();

	Grille g1 = lirefichier(argv[1]);
	
	joueur j1;
	j1.posn = g1.n / 2;
	j1.posm = g1.m / 2;
	
	j1.pv = 10;
	j1.atk = 3;
	j1.def = 2;
	j1.pvmax = 50;
	
	g1 = posjoueur(g1, j1);
	
	afficheGrillew(g1);
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
		printw("\nDefence : %d\n\n", j1.def);
		printw("Inventaire : \n");
		def_inventaire(j1);
		
		j1 = deplacement(g1, j1);
		j1 = type_salle(g1, j1);
	}

	printf("\n Il y a %d cases non vides\n\n", nbcasesnonvides(g1));
}
