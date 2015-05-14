CC = gcc
C99 = -std=c99
SDLFLAGS = `pkg-config --cflags --libs sdl --libs SDL_image`
CFLAGS = -g -Wall
EXE = main
OPATH = obj
BPATH = bin
IPATH = include
SPATH = src

$(EXE) : $(OPATH)/main.o $(OPATH)/grille.o $(OPATH)/joueur.o
	$(CC) $(SDLFLAGS) -o $@ $(CFLAGS) $^ $(C99)
	mv $(EXE) $(BPATH)/

$(OPATH)/grille.o : $(SPATH)/grille.c $(IPATH)/grille.h 
	$(CC) -c $(CFLAGS) $<
	
$(OPATH)/joueur.o : $(SPATH)/joueur.c $(IPATH)/joueur.h
	$(CC) -c $(CFLAGS) $<
	
$(OPATH)/main.o : $(SPATH)/main.c $(IPATH)/grille.h $(IPATH)/joueur.h
	$(CC) $(SDLFLAGS) -c $(CFLAGS) $<

clean:
	rm $(OPATH)/*
	rm $(BPATH)/$(EXE)
	
