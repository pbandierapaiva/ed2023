// Trbalhando com matrizes esparsas
// Exemplo utilizando arquivos de variantes genéticas (VCF)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	short int v1;
	short int v2;
} VALOR;

typedef struct no {
	// short int v1,v2;
	VALOR val;
	struct no *prox;
	short int chr;
	int offset;
	} NO;
	
typedef NO* PTRNO;

typedef struct {
	short int nChr;
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

bool insereElemento( MATRIZ *m, short int chrom, int offset, int sujeito, short int pv1, short int pv2 ) {
	PTRNO ant = NULL;
	PTRNO atual;
	
	if( !(chrom>0 && chrom <= m->nChr && offset>0 && sujeito>=0 && sujeito < m->nSujeitos) )
		return false;

	atual = m->sujeitos[ sujeito ];
	while( atual!=NULL && atual->chr < chrom && atual->offset < offset ) {
		ant = atual;
		atual = atual->prox;
	}
	if( atual!=NULL && atual->chr==chrom && atual->offset==offset ) {
		if( pv1==0 && pv2==0 ) {
			if(ant==NULL) m->sujeitos[ sujeito ]= atual->prox;
			else ant->prox = atual->prox;
			free(atual);
		}
		atual->val.v1 = pv1;
		atual->val.v2 = pv2;
	}
	else if( pv1!=0 || pv2!=0 ) {
		PTRNO novo = (PTRNO) malloc( sizeof(NO));
		novo->val.v1 = pv1;
		novo->val.v2 = pv2;
		novo->chr = chrom;
		novo->offset = offset;
		novo->prox=atual;
		if(ant==NULL) m->sujeitos[ sujeito ]=novo;
		else ant->prox=novo;
	}
	return true;
}

VALOR valorElemento(MATRIZ *m, short int chrom, int offset, int sujeito) {
	PTRNO atual;
	VALOR v;
	v.v1=0;
	v.v2=0;
	
	if( !(chrom>0 && chrom <= m->nChr && offset>0 && sujeito>=0 && sujeito < m->nSujeitos) )
		return v;
	
	atual = m->sujeitos[sujeito];

	if( atual!=NULL && atual->chr < chrom && atual->offset < offset) 
		atual = atual->prox;
	
	if( atual!=NULL && atual->chr==chrom && atual->offset==offset)
		return atual->val;
	return v;
}
	
	
int main() {


	MATRIZ vcf;
	VALOR v;

	inicializaMat( &vcf, 23, 10);
	insereElemento( &vcf, 1, 1097335, 0, 1,0 );
	insereElemento( &vcf, 1, 1852484, 1, 1,0 );
	insereElemento( &vcf, 1, 2338569, 2, 1,1 );
	insereElemento( &vcf, 1, 2889577, 3, 1,0 );
	insereElemento( &vcf, 1, 3368143, 4, 1,1 );

	v = valorElemento(&vcf, 1, 1097335, 0 );
	printf("Valor %d / %d\n",v.v1,v.v2);
	v = valorElemento(&vcf, 1, 1852484, 1 );
	printf("Valor %d / %d\n",v.v1,v.v2);
	v = valorElemento(&vcf, 1, 2338569, 2 );
	printf("Valor %d / %d\n",v.v1,v.v2);
	v = valorElemento(&vcf, 1, 2889577, 3 );
	printf("Valor %d / %d\n",v.v1,v.v2);
	v = valorElemento(&vcf, 1, 2889577, 4 );
	printf("Valor %d / %d\n",v.v1,v.v2);
}
	
	
	
	
