main : grille.o joueur.o main.o
	gcc -o main -Wall main.o grille.o joueur.o -lncurses

grille.o : grille.h grille.c
	gcc -c -g grille.c
	
joueur.o : joueur.h joueur.c
	gcc -c -g joueur.c
	
main.o : main.c grille.h joueur.h
	gcc -c -g main.c

clean :
	rm *.o
	rm main
