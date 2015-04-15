#ifndef __JOUEUR_
#define __JOUEUR_

	typedef struct
	{
		int posn; //position du joueur en x
		int posm; //position du joueur en y
		int pv; // points de vie
		int atk; // points d'attaque
		int def; //points de défense
		int pvmax; //maximum de point de vie (définie pour chaque joueur)
		int **inventaire; //Tableau de caractères représentant l'inventaire
	} joueur;
	
	Grille posjoueur (Grille g1, joueur j1); //Position actuelle du joueur
	Grille retiretrace (Grille g1, joueur j1); //Retire le # du joueur à la case d'avant
	joueur deplacement (Grille g1, joueur j1); //Déplace le joueur
	joueur type_salle (Grille g1, joueur j1); //Salles soignantes; blessantes ou neutres
	int chemin_valide (joueur *chemin, Grille g1, int nbdeplacements); //Juge si le chemin est valide en fonction d'une grille et d'un chemin (représenté sous la forme d'un tableau de positions du joueur)
#endif
