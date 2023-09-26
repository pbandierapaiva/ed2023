// Lista duplamente encadeada
//
//
#include <stdio.h>
#include <stdlib.h>

typedef struct  listaDE {
	int carga;
	struct listaDE *ant;
	struct listaDE *prox;
} ListaDE;

void insereLista( ListaDE **l, int valor ) {
	ListaDE *novoNo, *ptr;

	novoNo = malloc( sizeof(ListaDE) );
	if( novoNo==NULL ) {
		printf("Erro de alocação de memória\n\n");
		exit(-1);
		}
	novoNo->carga = valor;
        novoNo->prox = NULL;
	novoNo->ant = NULL;

        if( *l==NULL ) {
                *l=novoNo;
                return;
        }
        ptr = *l;
        while( ptr->prox != NULL )
                ptr = ptr->prox;
        ptr->prox = novoNo;
	novoNo->ant = ptr;     
}

void imprimeLista( ListaDE *l ) {
	ListaDE *ptr;

	printf("\nImprimindo lista duplamente encadeada\n");
	ptr = l;
	if( !ptr ) {
		printf("lista vazia\n");
		return;
	}
	while( ptr ) {
		printf("%d\n", ptr->carga );
		ptr = ptr->prox;
	}
}


void imprimeListaInvertida( ListaDE *l ) {
	ListaDE *ptr;

	printf("\nImprimindo lista duplamente encadeada INVERTIDA\n");
	ptr = l;
	if( !ptr ) {
		printf("lista vazia\n");
		return;
	}
	while( ptr->prox )  // vai até o final da lista
		ptr = ptr->prox;
	do {
		printf("%d\n", ptr->carga );
		ptr = ptr->ant;
	} while( ptr );
}

int main() {
	int inteiroLido;

	ListaDE *lista, *novoElemento, *ptr, *ptrAnt;
	lista=NULL;
	printf("\nEntre com inteiros positivos (0 termina)\n");
	while( 1 ) {
		printf("\n> ");
		scanf("%d", &inteiroLido);
		if( inteiroLido <=0 )
			break;
		
		insereLista( &lista, inteiroLido); 
	}
	imprimeLista( lista );
	imprimeListaInvertida( lista);
	return 0;
	
	
}

