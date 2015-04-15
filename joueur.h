#ifndef __JOUEUR_
#define __JOUEUR_

	typedef struct
	{
		int posn;
		int posm;
		int pv;
		int atk;
		int def;
		int pvmax;
		int **inventaire;
	} joueur;
	
	Grille posjoueur (Grille g1, joueur j1);
	Grille retiretrace (Grille g1, joueur j1);
	joueur deplacement (Grille g1, joueur j1);
	joueur type_salle (Grille g1, joueur j1);
#endif
