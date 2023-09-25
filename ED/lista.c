// Lista encadeada
//
//
#include <stdio.h>

struct  listaS {
	int carga;
	struct listaS *prox;
}


int main() {
	int inteiroLido;

	struct ListaS *lista, *novoElemento, *ptr;

	lista=NULL;

	printf("\nEntre com inteiros positivos (0 termina)\n")

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
		novoElemento->prox = lista;
		lista = novoElemento;     
	}
	
// percorre a lista
	ptr = lista;
	while( ptr ) {
		printf("%d\n", ptr->carga );
		ptr = ptr->prox;
	}

	return 0;
}

