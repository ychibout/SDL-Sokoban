CC = gcc
C99 = -std=c99
SDLFLAGS = `pkg-config --cflags --libs sdl --libs SDL_image`
CFLAGS = -g -Wall
EXE = main
BPATH = bin
IPATH = include
SPATH = src

$(EXE) : main.o grille.o joueur.o
	$(CC) $(SDLFLAGS) -o $@ $(CFLAGS) $^ $(C99)
	mv $(EXE) $(BPATH)/

grille.o : $(SPATH)/grille.c $(IPATH)/grille.h 
	$(CC) -c $(CFLAGS) $<
	
joueur.o : $(SPATH)/joueur.c $(IPATH)/joueur.h
	$(CC) -c $(CFLAGS) $<
	
main.o : $(SPATH)/main2.c $(IPATH)/grille.h $(IPATH)/joueur.h
	$(CC) $(SDLFLAGS) -c $(CFLAGS) $<

clean:
	rm $(OPATH)/*
	rm $(BPATH)/$(EXE)
	
