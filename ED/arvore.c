// arvore.c - implementação de árvore binária
//

#include <stdio.h>
#include <stdlib.h>


typedef struct no {
	int carga;	

	struct no *noE;
	struct no *noD;
	} NO;

void insere( NO **, int  );
NO *checaAVL( NO *noPai );
void insereAVL( NO **noPai, int valor );
int altura( NO *meuNo );
int fb( NO *no );
NO *pai( NO *r, NO *noInteresse );

	
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



void insereAVL( NO **noPai, int valor ){
	NO *novoNo;
	int fbPai;
	
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
		
		insere( &((*noPai)->noE ), valor);
		}
	else {
		if(fbPai==1)  // desbalanceou
		
		insere( &((*noPai)->noD ), valor);
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
// Fator de balanceamento
int fb( NO *no ) {
	return altura( no->noD ) - altura( no->noE );
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
void populaArvore( NO **noPai ){

/*	insere( noPai, 1);
	insere( noPai, 3);	
	insere( noPai, 5);	
	insere( noPai, 7);
	insere( noPai, 9);	
	insere( noPai, 12);
	insere( noPai, 43);
	insere( noPai, 34);	
	insere( noPai, 4);	
	insere( noPai, 6);
	insere( noPai, 17);	
	insere( noPai, 18);
	insere( noPai, 19);
	insere( noPai, 20);	
	insere( noPai, 11);	
	insere( noPai, 45);
	insere( noPai, 98);	
	insere( noPai, 72);*/
	
	insere( noPai, 50); //p
	insere( noPai, 20); //u
	insere( noPai, 30); //v
 	insere( noPai, 1); // T1
 	insere( noPai, 25); // T2
 	insere( noPai, 40); // T3
 	insere( noPai, 99); // T4
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











