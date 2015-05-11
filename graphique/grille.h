#ifndef __GRILLE_
#define __GRILLE_

/**
* @file     joueur.h
* @author   Yanis Chibout
* @version  1.0
* @date     avril 2015
* @brief    header de grille.c
*/

	typedef struct
	{
		int **g; //La grille en elle-même
		int n; //nombre de lignes
		int m; //nombre de colonnes
		int effect; //effets d'une salle sur le joueur
	} Grille;
	
	Grille creerGrille (Grille g1); //initialise une grille
	Grille lirefichier (); //lis un fichier entré en premier argument (argv[1]) et en fait une grille (les bords doivent être dans le fichier)
#endif
