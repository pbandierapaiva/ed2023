##
##

CC = gcc
CFLAG = -g

all : buscaindexe buscagexe criaindexe

clean : 
	rm *.o

buscaindexe : buscaIndexadaCadGeral.o utilCadastro.o
	$(CC) -o buscaindexe buscaIndexadaCadGeral.o utilCadastro.o
	
buscagexe : buscaCadGeral.o utilCadastro.o
	$(CC) -o buscagexe buscaCadGeral.o utilCadastro.o

criaindexe : criaIndiceCadastro.o  utilCadastro.o
	$(CC) -o criaindexe criaIndiceCadastro.o  utilCadastro.o
	
utilCadastro.o : utilCadastro.c cadastro.h
	$(CC) $(CFLAG) -c utilCadastro.c
	
buscaCadGeral.o : buscaCadGeral.c  cadastro.h
	$(CC) $(CFLAG) -c buscaCadGeral.c
	
buscaIndexadaCadGeral.o : buscaIndexadaCadGeral.c cadastro.h
	$(CC) $(CFLAG) -c  buscaIndexadaCadGeral.c

criaIndiceCadastro.o : criaIndiceCadastro.c cadastro.h
	$(CC) $(CFLAG) -c   criaIndiceCadastro.c







	
