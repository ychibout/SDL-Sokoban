CMODE = console
GMODE = graphique
EXE = main
GRILLE = test.txt
BPATH = bin

console :
	cd $(CMODE)
	make
	./$(EXE) $(GRILLE)
	
graphique :
	cd $(GMODE)
	make
	./$(BPATH)/$(EXE) $(GRILLE)
	
clean :
	cd $(CMODE)/
	make clean
	cd ../$(GMODE)/
	make clean
