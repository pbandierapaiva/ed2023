// Fila - FIFO First in first out
//    enqueue <- coloca no final da fila
//    dequeue <- retira o primeira da fila
//    isEmpty  <- verifica se a pilha está vazia
//    size <- retorna tamanho da pilha

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct  fila {
	int carga;
	struct fila *prox;
} Fila;

void enqueue( Fila **fila,  int valor ) {
	Fila *novoNo, *ptr;
	
	novoNo = malloc( sizeof(Fila) );
	if(!novoNo) {
		printf("\nERRO - alocação de memória\n\n");
		exit(-1);
		}
	novoNo->carga = valor;
	novoNo->prox  = NULL;
	
	if( *fila==NULL ) { // Fila vazia
		*fila = novoNo;
		return;
		}
	ptr = *fila;
	while( ptr->prox!=NULL )
		ptr = ptr->prox;
	ptr->prox = novoNo;
	}

int dequeue( Fila **fila ) {
	Fila *topo;
	int val;
	
	if(*fila==NULL)  {  //fila vazia
		printf("\nFila vazia!\n");
		return 0;
		}
	topo = *fila;
	*fila = topo->prox;
	val = topo->carga;
	free(topo);
	return val;
	}

int isEmpty( Fila *fila ){
	if(fila==NULL)
		return 1;
	else
		return 0;
	}

int size( Fila *fila ){
	Fila *ptr;
	int contador=0;
	
	ptr = fila;
	while(ptr!=NULL) {
		contador++;
		ptr = ptr->prox;
		}
	return contador;
	}
void imprimeFila( Fila *fila ){
	Fila *ptr;

	ptr = fila;
	while(ptr) {
		printf("\n%d",ptr->carga);
		ptr = ptr->prox;
	}	
	printf("\n\n");
}

int main(){
	Fila *minhaFila = NULL;
	char op;
	int dado;
	int continua=1;

	while(continua) {
		printf("\n*** Entre com opção:\n\tI - insere\n\tR - retira");
		printf("\n\tT - Tamanho\n\tP - Imprimir\n\tX - Sair\n");

		scanf(" %c", &op);
		op = toupper(op);
		
		switch(op) {
		case 'I':
			printf("Inserindo dado: ");
			scanf( "%d", &dado );
			enqueue( &minhaFila, dado);
			break;
		case 'R':
			dado = dequeue( &minhaFila );
			printf("Retirado: %d da fila.\n", dado);
			break;
		case 'T':
			printf("\nA fila tem %d elementos.\n", size(minhaFila));
			break;
		case 'P':
			imprimeFila(minhaFila);
			break;
		case 'X':
			continua=0;
			break;
		}
	}
}
