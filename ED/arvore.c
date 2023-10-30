// arvore.c - implementação de árvore binária de busca
//

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
	
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

// Fator de balanceamento
int fb( NO *no ) {
	return altura( no->noD ) - altura( no->noE );
}

NO *checaAVL( NO *noPai ){
	int fbPai;
	NO *p;
	
	if(noPai==NULL) 
		return NULL;
		
	fbPai = fb(noPai);
	if( fbPai>1 || fbPai<-1 )
		return noPai;
	
	p = checaAVL( noPai->noD );
	if( p ) return p;
	p = checaAVL( noPai->noE );
	if( p ) return p;
	
	return NULL;
}

// insereAVL - insere nó mantendo a árvore AVL
void insereAVL( NO **noPai, int valor ){
	NO *novoNo;
	int fbPai;
	int desbalanceado = 0;
	
	novoNo = malloc( sizeof(NO) );
	if(novoNo==NULL) exit(-1);
	novoNo->carga = valor;
	novoNo->noE = NULL;
	novoNo->noD = NULL;	

	if( *noPai == NULL ) { 
		*noPai = novoNo;
		return;
		}
			
	fbPai = fb( *noPai );

	if( (*noPai)->carga > valor) {
		if(fbPai==-1) // desbalanceou
			desbalanceado = 1;
		insere( &((*noPai)->noE ), valor);
		}
	else {
		if(fbPai==1)  // desbalanceou
			desbalanceado = 1;		
		insere( &((*noPai)->noD ), valor);
		}
	if( desbalanceado )
		balanceiaAVL(noPai);
		
}

void balanceiaAVL( NO **no) {
	int fator, ffe, ffd;

	fator = fb(*no);
	if( fator >= -1 && fator <= 1 ){
		return ;
	}
	
	if(fator==-2) {
		ffe = fb( (*no)->noE );
		ffd = fb( (*no)->noD );
		if  ( ffe==+1 || ffd==+1 ) {
			if( ffe == 1 ) {
				rotacaoEsquerda( &(*no)->noE );
			}
			else {// ffd == +1
				rotacaoEsquerda( &(*no)->noD );
			}
		}
		rotacaoDireita( no );
	}
	if(fator==2){
		ffe = fb( (*no)->noE );
		ffd = fb( (*no)->noD );
		if  ( ffe==-1 || ffd==-1 ) {
			if( ffe == 1 ) {
				rotacaoDireita( &(*no)->noE );
			}
			else {// ffd == +1
				rotacaoDireita( &(*no)->noD );
			}
		}
		rotacaoEsquerda( no );
	}


}

int altura( NO *meuNo ){
	int alturaD=0;
	int alturaE=0;
	
	if( !meuNo ) return 0;
	
	if( meuNo->noD == NULL && meuNo->noE == NULL )
		return 1;
	if( meuNo->noD )   // meuNo->noD != NULL
		alturaD = altura( meuNo->noD );
	if( meuNo->noE )  // meuNo->noE != NULL
		alturaE = altura( meuNo->noE );
	if( alturaE > alturaD )
		return alturaE+1;
	else
		return alturaD+1;
}

/* 
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
*/ 
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

/*
void encontraNoePai(NO *raiz) {
	NO *n, *p;
	int valor;	

	while(1) {
		printf("\nEntre com carga a ser encontrada (0 termina): ");
		scanf("%d", &valor);
		if(!valor) return;
			
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
*/

void populaArvore( NO **noPai ){

	insereAVL( noPai, 1);
	insereAVL( noPai, 3);	
	insereAVL( noPai, 5);	
	insereAVL( noPai, 7);
	insereAVL( noPai, 9);	
	insereAVL( noPai, 12);
	insereAVL( noPai, 43);
	insereAVL( noPai, 34);	
	insereAVL( noPai, 4);	
	insereAVL( noPai, 6);
	insereAVL( noPai, 17);	
	insereAVL( noPai, 18);
	insereAVL( noPai, 19);
	insereAVL( noPai, 20);	
	insereAVL( noPai, 11);	
	insereAVL( noPai, 45);
	insereAVL( noPai, 98);	
	insereAVL( noPai, 72);
	
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
// Rotação Direita
void rotacaoDireita( NO **pai ){
	NO *p, *u;
	p = *pai;
	u = p->noE;
	*pai = u;
	p->noE = u->noD;
	u->noD = p;
}
// Rotação Esquerda
void rotacaoEsquerda( NO **pai ){
	NO *p, *u;
	p = *pai;
	u = p->noD;
	*pai = u;
	p->noD = u->noE;
	u->noE = p;
}
// Rotação DuplaDireita
void rotacaoDuplaDireita( NO **pai ){
	NO *p;
	
	p = *pai;
	rotacaoEsquerda( &(p->noE) );
	rotacaoDireita( pai );
}
// Rotação DuplaEsquerda
void rotacaoDuplaEsquerda( NO **pai ){
	NO *p;
	
	p = *pai;
	rotacaoDireita( &(p->noD) );
	rotacaoEsquerda( pai );
}	

void emOrdem( NO *noPai ) {
	if( noPai->noE )
		emOrdem(noPai->noE);
	printf("%d - FB: %d\n", noPai->carga,  fb(noPai) );
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
	NO *ptr;
	// entraDados( &raiz );
	
	populaArvore( &raiz );
	
	printf("\nA altura da árvore binária é: %d\n\n", altura(raiz) );

	emOrdem( raiz );
	ptr = checaAVL(raiz);
	if( !ptr) 
		printf("árvore balanceada\n");
	else
		printf("árvore não balanceada no nó com carga %d\n", ptr->carga);
	//rotacaoEsquerda(&raiz);
	//printf("\n");
	//emOrdem( raiz );
	rotacaoDuplaDireita( &raiz );
	emOrdem( raiz );	
	ptr = checaAVL(raiz);
	if(!ptr)
		printf("árvore balanceada\n");
	else
		printf("árvore não balanceada no nó com carga %d\n", ptr->carga);
}











