#include <stdlib.h>
#include <stdio.h>
#include "../include/grille.h"

/**
* @file		grille.c
* @author	Yanis Chibout
* @version	1.1
* @date		mai 2015
* @brief	Fonctions liées à la grille
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

Grille lirefichier (char *fichier) //Les bords doivent être contenus dans le fichier de la grille
{
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

