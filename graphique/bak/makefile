CC = gcc
C99 = -std=c99
SDLFLAGS = `pkg-config --cflags --libs sdl --libs SDL_image`
CFLAGS = -g -Wall
EXE = main

$(EXE) : main2.o grille.o joueur.o
	$(CC) $(SDLFLAGS) -o $@ $(CFLAGS) $^ $(C99) 

grille.o : grille.c grille.h 
	$(CC) -c $(CFLAGS) $<
	
joueur.o : joueur.c joueur.h
	$(CC) -c $(CFLAGS) $<
	
main2.o : main2.c grille.h joueur.h
	$(CC) $(SDLFLAGS) -c $(CFLAGS) $<

clean:
	rm *.o
	rm $(EXE)
	
