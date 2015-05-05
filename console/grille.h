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
	void desalloueGrille (Grille g1); //libère l'espace mémoire allouée pour la grille entrée
	void afficheGrille (Grille g1); //affiche la grille
	Grille lirefichier (); //lis un fichier entré en premier argument (argv[1]) et en fait une grille (les bords doivent être dans le fichier)
	int nbcasesnonvides (Grille g1); //compte le nombre de cases non-vides
	void afficheGrillew (Grille g1); //affiche une grille de meilleure qualité (dépend de ncurses.h)
	/*void rotation (grille g1);*/ //Rotation de 90° par rapport à la diagonale
#endif
