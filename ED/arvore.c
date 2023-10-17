// arvore.c - implementação de árvore binária
//

#include <stdio.h>
#include <stdlib.h>


typedef struct no {
	int carga;	

	struct no *noE;
	struct no *noD;
	} NO;
	
void insere( NO **noPai, int valor ){
	NO *novoNo;
	
	novoNo = malloc( sizeof(NO) );
	if(novoNo==NULL) exit(-1);
	novoNo->carga = valor;
	novoNo->noE = NULL;
	novoNo->noD = NULL;	
	
	if( *noPai == NULL ) { 
		*noPai = novoNo;
		return;
		}
	if( (*noPai)->carga > valor) 
		insere( &((*noPai)->noE ), valor);
	else
		insere( &((*noPai)->noD ), valor);
}

int altura( NO *meuNo ){
	int alturaD=0;
	int alturaE=0;
	
	if( meuNo->noD == NULL && meuNo->noE == NULL )
		return 0;
	if( meuNo->noD )   // meuNo->noD != NULL
		alturaD = altura( meuNo->noD );
	if( meuNo->noE )  // meuNo->noE != NULL
		alturaE = altura( meuNo->noE );
	if( alturaE > alturaD )
		return alturaE+1;
	else
		return alturaD+1;
}

NO *pai( NO *r, NO *noInteresse ) {
	
	if( noInteresse == r ) return NULL;
	
	if( noInteresse->carga > r->carga ) {
		if( r->noD == noInteresse )
			return r;
		return pai( r->noD, noInteresse );
	}
	else {
		if( r->noE == noInteresse )
			return r;
		return pai( r->noE, noInteresse );
	}
}

NO *buscaNo( NO *raiz, int valor ){
	if( raiz->carga == valor )
		return raiz;
	if( valor > raiz->carga ) {
		if(raiz->noD==NULL) return NULL;
		return buscaNo(raiz->noD, valor);
	}
	else {
		if(raiz->noE==NULL) return NULL;
		return buscaNo(raiz->noE, valor);
	}

}

void encontraNoePai(NO *raiz) {
	NO *n, *p;
	int valor;	

	while(1) {
		printf("\nEntre com carga a ser encontrada (0 termina): ");
		scanf("%d", &valor);
		if(!valor) return 0;
			
		n = buscaNo( raiz, valor );
		if(n) {
			p = pai( raiz, n );
			
			printf("Encontrado em %ld carga %d\n", (long int)n, n->carga);
			if(p)
				printf("O pai do nó tem carga  %d\n", p->carga);
			else
				printf("Esse nó não tem pai, é a raiz da árvore\n");
			
			}
		else
			printf("Carga não encontrada\n");
		}
}

void entraDados( NO **noPai ){
	int inteiroLido;
	
	printf("\nEntre com inteiros positivos (0 termina)\n");
	while( 1 ) {
		printf("\n> ");
		scanf("%d", &inteiroLido);
		if( inteiroLido <=0 )
			break;
		
		insere( noPai, inteiroLido); 
	}
}

void emOrdem( NO *noPai ) {
	if( noPai->noE )
		emOrdem(noPai->noE);
	printf("%d\n", noPai->carga );
	if( noPai->noD )
		emOrdem(noPai->noD);
}

void preOrdem( NO *noPai ) {
	printf("%d\n", noPai->carga );
	if( noPai->noE )
		emOrdem(noPai->noE);
	if( noPai->noD )
		emOrdem(noPai->noD);
}

void posOrdem( NO *noPai ) {
	if( noPai->noE )
		emOrdem(noPai->noE);
	if( noPai->noD )
		emOrdem(noPai->noD);
	printf("%d\n", noPai->carga );
}

int main() {
	NO *raiz = NULL;

	entraDados( &raiz );
	printf("\nA altura da sua árvore binária é: %d\n\n", altura(raiz) );

	emOrdem( raiz );
	
	encontraNoePai( raiz );
	
}











