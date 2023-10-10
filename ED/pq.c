// Implementação de Fila com prioridade (Priority Queue - PQ)  usando lista encadeada
//
//
#include <stdio.h>
#include <stdlib.h>

typedef struct  listaS {
	int carga;
	struct listaS *prox;
} ListaSE;

int insere( ListaSE **pq, int valor ){
	ListaSE *novoItem, *ptr, *ptrAnt;
	
	novoItem = malloc( sizeof(ListaSE) );
	if( !novoItem ) return -1;
	
	novoItem->carga = valor;
	novoItem->prox = NULL;
	
	if( *pq ) {
		ptrAnt = pq;
		ptr = *pq;
		
		while( ptr->carga > novoItem->carga || ptr==NULL ) {
			ptrAnt = ptr;
			ptr = ptr->prox;
			}
		ptrAnt->prox = novoItem;
		novoItem->prox = ptr;
		}
	else 
		*saco = novoItem;
	return 0;	
}

ListaSE *max( ListaSE **pq ) {
	return *pq
}

ListaSE *delMax( ListaSE **pq ) {
	ListaSE *cabeca;
	
	cabeca = *pq;
	if( *pq!=NULL )
		*pq = cabeca->prox;

	return cabeca;
}

int size( ListaSE *paddq ){
	ListaSE *ptr;
	int contador=0;
	ptr = pq;
	while( ptr ) {
		contador++;
		ptr = ptr->prox;
		}
	return contador;
	}

int isEmpty(ListaSE *pq ){
	if(pq==NULL) return 1;
	return 0;
}	



int main() {
	int inteiroLido;
	int item;

	ListaSE *pq;
	ListaSE *ptr;

	pq=NULL;
	
	printf("\nEntre com inteiros positivos (0 termina)\n");

	while( 1 ) {
		printf("\n> ");
		scanf("%d", &inteiroLido);
		if( inteiroLido <=0 )
			break;
		insere(&pq, inteiroLido);
	}

	do {
		ptr = delMax(&pq);
		item = ptr->carga; 
		free(ptr);
		printf("%d\n", item->carga);

	} while(item);
}

