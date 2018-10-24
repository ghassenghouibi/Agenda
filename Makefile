# définition des cibles particulières
.PHONY: clean, mrproper
 
# désactivation des règles implicites
#.SUFFIXES:
 
# définition des variables
CC = gcc
CFLAGS = -W -Wall 
 
 
 
# all
all: main.o gestiondesrendez_vous.o getsave.o menu.o connexion.o extra.o
	$(CC) main.o gestiondesrendez_vous.o getsave.o menu.o connexion.o extra.o -o Agenda

main.o: main.c projet.h
	$(CC) -c main.c -o main.o $(CFLAGS)

gestiondesrendez_vous.o: gestiondesrendez_vous.c projet.h
	$(CC) -c gestiondesrendez_vous.c -o gestiondesrendez_vous.o $(CFLAGS)

getsave.o: getsave.c projet.h
	$(CC) -c getsave.c -o getsave.o $(CFLAGS) 

menu.o: menu.c projet.h
	$(CC) -c menu.c -o menu.o $(CFLAGS)

connexion.o: connexion.c projet.h
	$(CC) -c connexion.c -o connexion.o $(CFLAGS)
extra.o :extra.c projet.h
	$(CC) -c extra.c -o extra.o $(CFLAGS)

# clean
clean:
	rm -rf *.bak rm -rf *.o
 
# mrproper
mrproper: clean
	rm -rf Programme
