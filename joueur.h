#ifndef __JOUEUR_
#define __JOUEUR_

/**
* @file		joueur.h
* @author	Yanis Chibout
* @version	1.0
* @date		avril 2015
* @brief	header de joueur.c

	typedef struct
	{
		int posn; //position en y
		int posm; //position en x
		int pv; //points de vie
		int atk; //points d'attaque
		int def; //points de défense
		int pvmax; //limite de points de vie
		char **inventaire; //inventaire (tableau de string)
	} joueur;
	
	joueur def_inventaire (joueur j1); //définition d'un inventaire
	/*void affiche_inventaire (joueur j1);*/ //affichage de l'inventaire
	Grille posjoueur (Grille g1, joueur j1); //définition de la position du joueur
	Grille retiretrace (Grille g1, joueur j1); //retire la trace du passage du joueur après déplacement (remplace le "#" par un " ")
	joueur deplacement (Grille g1, joueur j1); //Déplacement du joueur (en attente d'une touche)
	joueur type_salle (Grille g1, joueur j1); //Salle blessante, soignante, neutre
	int chemin_valide (joueur *chemin, Grille g1, int nbdeplacements); //Juge si le chemin est valide en fonction d'une grille et d'un chemin (représenté sous la forme d'un tableau de positions du joueur)
#endif
