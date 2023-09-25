// Lista encadeada
//
//
#include <stdio.h>
#include <stdlib.h>

struct  listaS {
	int carga;
	struct listaS *prox;
};

int main() {
	int inteiroLido;

	struct listaS *lista, *novoElemento, *ptr, *ptrAnt;

	lista=NULL;

	printf("\nEntre com inteiros positivos (0 termina)\n");

	while( 1 ) {
		printf("\n> ");
		scanf("%d", &inteiroLido);
		if( inteiroLido <=0 )
			break;

		novoElemento = malloc( sizeof(struct listaS) );
		if( novoElemento==NULL ) {
			printf("Erro de alocação de memória\n\n");
			break;
		}
		novoElemento->carga = inteiroLido;
		novoElemento->prox = NULL;
		
		ptr = lista;
		if( ptr==NULL ) {
			lista = novoElemento;
		}
		else {
			while( ptr->prox!=NULL ) {
				ptr = ptr->prox;
			}
			ptr->prox = novoElemento;
		}
		
	}
	
// percorre a lista
	ptr = lista;
	while( ptr ) {
		printf("%d\n", ptr->carga );
		ptr = ptr->prox;
	}

	printf("\nDeseja remover que elemento: ");
	scanf("%d", &inteiroLido);
	
	ptr = lista;
	if(ptr->carga==inteiroLido) {
		lista = lista->prox;
		free(ptr);
	}
	else {
		while( ptr!=NULL ) {
			if(ptr->prox==NULL)
				break;
			if(ptr->prox->carga==inteiroLido) {
				ptrAnt=ptr->prox;
				ptr->prox = ptr->prox->prox;
				free(ptrAnt);
				}
			ptr = ptr->prox;
		}
	
	}
	
// percorre a lista
	ptr = lista;
	while( ptr ) {
		printf("%d\n", ptr->carga );
		ptr = ptr->prox;
	}

	return 0;
	
	
}

