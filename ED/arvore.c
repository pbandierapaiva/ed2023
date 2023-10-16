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

int main() {
	NO *raiz = NULL;	

	entraDados( &raiz );
	printf("\nA altura da sua árvore binária é: %d\n\n", altura(raiz) );

	emOrdem( raiz );
}











