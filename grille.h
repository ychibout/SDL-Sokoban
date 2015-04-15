#ifndef __GRILLE_
#define __GRILLE_

	typedef struct
	{
		int **g; //Grille en elle-même
		int n; //nombre de lignes
		int m; // nombre de colonnes
		int effect; //grille soignante, blessante ou neutre (voir type_salle)
	} Grille;
	
	Grille creerGrille (Grille g1); //Initialise une grille à 0
	void desalloueGrille (Grille g1); //Retire l'espace mémoire dédiée à une grille
	void afficheGrille (Grille g1); //Affiche la grille
	Grille lirefichier (); //Lis un fichier (entré en premier paramètre argv[1])
	int nbcasesnonvides (Grille g1); //Compte le nombre de cases non-vides
	void afficheGrillew (Grille g1);//Affiche la grille (avec ncurses.h)
#endif
