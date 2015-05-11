CC = gcc
C99 = -std=c99
SDLFLAGS = `pkg-config --cflags --libs sdl --libs SDL_image`
CFLAGS = -g -Wall
EXE = main
OPATH = obj
BPATH = bin
IPATH = include
SPATH = src

$(EXE) : main.o grille.o joueur.o
	$(CC) $(SDLFLAGS) -o $@ $(CFLAGS) $^ $(C99)
	mv $@ $(BPATH)

grille.o : grille.c grille.h 
	$(CC) -c $(CFLAGS) $<
	
joueur.o : joueur.c joueur.h
	$(CC) -c $(CFLAGS) $<
	
main.o : main.c grille.h joueur.h
	$(CC) $(SDLFLAGS) -c $(CFLAGS) $<

clean:
	rm $(EXE)
