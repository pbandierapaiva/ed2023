// Lista encadeada
//
//
#include <stdio.h>
#include <stdlib.h>

typedef struct  listaS {
	int carga;
	struct listaS *prox;
} ListaSE;

void insereLista( ListaSE **l, int valor ) {
	ListaSE *novoNo, *ptr;

	novoNo = malloc( sizeof(ListaSE) );
	if( novoNo==NULL ) {
		printf("Erro de alocação de memória\n\n");
		exit(-1);
		}
	novoNo->carga = valor;
	novoNo->prox = NULL;

	if( *l==NULL ) {
		*l=novoNo;
		return;
	}
	ptr = *l;
	while( ptr->prox != NULL )
		ptr = ptr->prox;
	ptr->prox = novoNo;	
}

void imprimeLista( ListaSE *l ) {
        ListaSE *ptr;

        printf("\nImprimindo lista encadeada\n");
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

void imprimeListaInvertidaRecursivo( ListaSE *l ) {
	if( l==NULL )
		return;
	imprimeListaInvertidaRecursivo( l->prox );
	printf("%d\n", l->carga );
}

void imprimeListaInvertida( ListaSE *l ) {

        printf("\nImprimindo lista encadeada INVERTIDA\n");
	if( !l ) {
		printf("lista vazia\n");
	        return;
	}
	imprimeListaInvertidaRecursivo( l );
}

int main() {
	int inteiroLido;

	ListaSE *lista, *novoElemento, *ptr, *ptrAnt;

	lista=NULL;

	printf("\nEntre com inteiros positivos (0 termina)\n");

	while( 1 ) {
		printf("\n> ");
		scanf("%d", &inteiroLido);
		if( inteiroLido <=0 )
			break;
		insereLista(&lista, inteiroLido);
		
	}
	
	imprimeLista(lista);	
	imprimeListaInvertida(lista);	
}

