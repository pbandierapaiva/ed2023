// Trbalhando com matrizes esparsas
// Exemplo utilizando arquivos de variantes genéticas (VCF)

#include <stdio.h>
#include <stdlib.h>


typedef struct no {
	int v1,v2;
	struct no *prox;
	int chr;
	int offset;
	} NO;
	
typedef NO* PTRNO;

typedef struct {
	int nChr;
	int nSujeitos;
	PTRNO *sujeitos;
	} MATRIZ;
	
void inicializaMat( MATRIZ *m, int numChrom, int numSujeitos ) {
	PTRNO	*aux;
	
	m->nChr = numChrom;
	m->nSujeitos = numSujeitos;
	
	m->sujeitos = malloc( numSujeitos * sizeof(PTRNO) );
	
	for( int i=0; i < m->nSujeitos; i++ )
		m->sujeitos[i] = NULL;
}	
	
	
	
	
	
	
	
