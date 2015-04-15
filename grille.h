#ifndef __GRILLE_
#define __GRILLE_

	typedef struct
	{
		int **g;
		int n;
		int m;
		int effect;
	} Grille;
	
	Grille creerGrille (Grille g1);
	void desalloueGrille (Grille g1);
	void afficheGrille (Grille g1);
	Grille lirefichier ();
	int nbcasesnonvides (Grille g1);
	void afficheGrillew (Grille g1);
#endif
