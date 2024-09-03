##
##

CC = gcc
CFLAG = -g

all : buscaindexe buscagexe criaindexe pegatamexe buscaindlistaexe buscaarvorebinexe criaHashCadastroexe

clean : 
	rm *.o

criaHashCadastroexe: criaHashCadastro.o utilCadastro.o
	$(CC) -o  criaHashCadastroexe criaHashCadastro.o utilCadastro.o

buscaarvorebinexe : buscaArvoreBin.o utilCadastro.o
	$(CC) -o buscaarvorebinexe buscaArvoreBin.o utilCadastro.o

pegatamexe : cadPegaTam.o utilCadastro.o
	$(CC) -o pegatamexe cadPegaTam.o utilCadastro.o
	
buscaindexe : buscaIndexadaCadGeral.o utilCadastro.o
	$(CC) -o buscaindexe buscaIndexadaCadGeral.o utilCadastro.o
	
buscagexe : buscaCadGeral.o utilCadastro.o
	$(CC) -o buscagexe buscaCadGeral.o utilCadastro.o

criaindexe : criaIndiceCadastro.o  utilCadastro.o
	$(CC) -o criaindexe criaIndiceCadastro.o  utilCadastro.o
	
buscaindlistaexe : buscaIndexadaCadGeralLista.o utilCadastro.o
	$(CC) -o buscaindlistaexe     buscaIndexadaCadGeralLista.o utilCadastro.o

buscaArvoreBin.o : buscaArvoreBin.c cadastro.h
	$(CC) $(CFLAG) -c buscaArvoreBin.c

cadPegaTam.o : cadPegaTam.c cadastro.h
	$(CC) $(CFLAG) -c cadPegaTam.c
	
utilCadastro.o : utilCadastro.c cadastro.h
	$(CC) $(CFLAG) -c utilCadastro.c
	
buscaCadGeral.o : buscaCadGeral.c  cadastro.h
	$(CC) $(CFLAG) -c buscaCadGeral.c
	
buscaIndexadaCadGeral.o : buscaIndexadaCadGeral.c cadastro.h
	$(CC) $(CFLAG) -c  buscaIndexadaCadGeral.c

criaIndiceCadastro.o : criaIndiceCadastro.c cadastro.h
	$(CC) $(CFLAG) -c   criaIndiceCadastro.c

buscaIndexadaCadGeralLista.o : buscaIndexadaCadGeralLista.c cadastro.h
	$(CC) $(CFLAG) -c   buscaIndexadaCadGeralLista.c 

criaHashCadastro.o : criaHashCadastro.c cadastro.h 
	$(CC) $(CFLAG) -c   criaHashCadastro.c 

	
