#include <stdlib.h>
#include <stdio.h>
#include "grille.h"

/**
* @file		grille.c
* @author	Yanis Chibout
* @version	1.0
* @date		avril 2015
* @brief	Fonctions liée à la grille
*/

Grille creerGrille (Grille g1)
{
	g1.g = (int **) malloc (g1.n * sizeof(int*));
	
	int i, j;
	for (i = 0; i < g1.n; i++)
	{
		g1.g[i] = (int*) malloc (g1.m * sizeof(int));
	}
	
	for (i = 0; i < g1.n; i++)
	{
		for (j = 0; j < g1.m; j++)
		{
			g1.g[i][j] = 0;
		}
	}
	
	return g1;
}

void desalloueGrille (Grille g1)
{
	int i;
	
	for (i = 0; i < g1.n; i++)
	{
		free(g1.g[i]);
	}
	
	free(g1.g);
}

void afficheGrille (Grille g1)
{
	int i, j;
	
	printf("\n\n");
	
	for (i = 0; i < g1.n; i++)
	{	
		for (j = 0; j < g1.m; j++)
		{	
			printf("%d ", g1.g[i][j]);
		}
		printf("|");
		
		printf("\n");
	}
}

Grille lirefichier (char *fichier) //Les bords doivent être contenus dans le fichier de la grille
{
	char line[100];
	
	int i, j;
	Grille g1;
	
	FILE *fd;
	fd = fopen(fichier, "r");
	
	if (fd == NULL)
	{
		perror("Erreur lors de la lecture du fichier");
		exit (1);
	}	
		fscanf(fd, "%d %d %d", &g1.n, &g1.m, &g1.effect);
		g1 = creerGrille(g1);
	
		while (!feof(fd))
		{
			for (i = 0; i < g1.n; i++)
			{
				for (j = 0; j < g1.m; j++)
				{
					fscanf(fd, "%d", &g1.g[i][j]);
				}
			}
		}

	fclose (fd);
	
	return g1;
}

int nbcasesnonvides (Grille g1)
{
	int i, j;
	int k = 0;
	
	for (i = 0; i < g1.n; i++)
	{
		for (j = 0; j < g1.m; j++)
		{
			if (g1.g[i][j] != 0)
			{
				k++;
			}
		}
	}
	
	return k;
}

void afficheGrillew (Grille g1) //Les bords doivent être contenus dans le fichier de la grille
{
	int i, j, k; 

	/*for (i = 0; i < g1.m+2; i++) //Face Nord
	{
		printw("O");
		refresh();
	}

	for (i = 1; i < g1.n+2; i++) //Face Ouest
	{
		mvprintw(i, 0, "O");
		refresh();
	}

	for (i = 1; i < g1.n+2; i++)
	{
		mvprintw(i, g1.m+1, "O"); //Face Est
		refresh();
	}

	for (i = 1; i < g1.m+2; i++)
	{
		mvprintw(g1.n+1, i, "O"); // Face Sud
		refresh();
	}*/

	for (i = 0; i < g1.n; i++)
	{
		for (j = 0; j < g1.m; j++)
		{	
			switch (g1.g[i][j])
			{
				case 0: mvprintw(i, j, " "); //Case libre
						refresh();
						break;

				case 1: mvprintw(i, j, "|"); //Mur
						refresh();
						break;

				case 2: mvprintw(i, j, "P"); //Augmentation PV
						refresh();
						break;
				
				case 3: mvprintw(i, j, "A"); //Augmentation attaque
						refresh();
						break;

				case 4: mvprintw(i, j, "D"); //Augmentation défense
						refresh();
						break;

				case 8: mvprintw(i, j, "#"); //Joueur
						refresh();
						break;	
				
				default: exit(1);
			}
		}

		printw("\n\n");
		refresh();
	}
}

/*
void rotation (grille g1)
{
	int i, j, temp;

	for (i = 0; i < g1.n; i++)
	{
		for (j = 0; j < g1.m; j++)
		{
			temp = g1.g[i][j];
			g1.g[i][j] = g1.g[j][i];
			g1.g[j][i] = temp;
		}
	}
}
*/
