// Implementação de SACO usando lista encadeada
//
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct  listaS {
	int carga;
	struct listaS *prox;
} ListaSE;

int sorteia(int max) {
	srandom(time(NULL));
	return (int) ( max * (random() / (pow(2,31) )));
	}

int tamanho( ListaSE *saco ){
	ListaSE *ptr;
	int contador=0;
	ptr = saco;
	while( ptr ) {
		contador++;
		ptr = ptr->prox;
		}
	return contador;
	}

void remover(ListaSE **saco, ListaSE *item) {
	ListaSE *ptr;
	
	ptr = *saco;
	if( ptr == item ) {	//remove primeiro item
		*saco = NULL;
		free(ptr);
		return;
		}
	while( ptr!=NULL && ptr->prox != item )
		ptr = ptr->prox;
	if(ptr==NULL) return;
	
	ptr->prox = item->prox;
	free(item);
	}

int add( ListaSE **saco, int valor ) {
	ListaSE *novoItem;
	
	novoItem = malloc( sizeof(ListaSE) );
	if( !novoItem ) return -1;
	
	novoItem->carga = valor;
	novoItem->prox = NULL;
	
	if( *saco )
		novoItem->prox = *saco;
	*saco = novoItem;
	
	return 0;
	}

int retira( ListaSE **saco ) {
	ListaSE *ptr;
	int tam, selecionado, ret;
	
	if( *saco==NULL ) return 0;
	tam = tamanho(*saco);
	
	selecionado = sorteia( tam );
	
	ptr = *saco;
	for( int i=0; i<selecionado; i++)
		ptr = ptr->prox;
	ret = ptr->carga;
	remover( saco, ptr );
	return ret;
	}



int main() {
	int inteiroLido;
	int item;

	ListaSE *saco;

	saco=NULL;

	printf("\nEntre com inteiros positivos (0 termina)\n");

	while( 1 ) {
		printf("\n> ");
		scanf("%d", &inteiroLido);
		if( inteiroLido <=0 )
			break;
		add(&saco, inteiroLido);
	}

	do {
		item = retira(&saco);
		printf("%d\n", item);
	} while(item);
}

