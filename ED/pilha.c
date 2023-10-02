// Pilha - LIFO Last in first out
//    pop <- retira o último elemento inserido
//    push <- insere elemento
//    peek <- olha o topo da pilha sem remover elementos
//    isEmpty  <- verifica se a pilha está vazia
//    size <- retorna tamanho da pilha

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct  pilha {
	int carga;
	struct pilha *prox;
} Pilha;

void push( Pilha **pilha,  int valor ) {
	Pilha *novoNo;
	
	novoNo = malloc( sizeof(Pilha) );
	if(!novoNo) {
		printf("\nERRO - alocação de memória\n\n");
		exit(-1);
		}
	novoNo->carga = valor;
	novoNo->prox  = *pilha;
	
	*pilha = novoNo;
	}

int pop( Pilha **pilha ) {
	Pilha *topo;
	int val;
	
	if(*pilha==NULL)  {  //pilha vazia
		printf("\nPilha vazia!\n");
		return 0;
		}
	topo = *pilha;
	*pilha = topo->prox;
	val = topo->carga;
	free(topo);
	return val;
	}

int isEmpty( Pilha *pilha ){
	if(pilha==NULL)
		return 1;
	else
		return 0;
	}

int peek( Pilha *pilha ){
	if(pilha==NULL){
		printf("\nPilha vazia!\n");
		return 0;
		}
	return pilha->carga;
	}	

int size( Pilha *pilha ){
	Pilha *ptr;
	int contador=0;
	
	ptr = pilha;
	while(ptr!=NULL) {
		contador++;
		ptr = ptr->prox;
		}
	return contador;
	}
void imprimePilha( Pilha *pilha ){
	Pilha *ptr;

	ptr = pilha;
	while(ptr) {
		printf("\n%d",ptr->carga);
		ptr = ptr->prox;
	}	
	printf("\n\n");
}

int main(){
	Pilha *minhaPilha = NULL;
	char op;
	int dado;
	int continua=1;

	while(continua) {
		printf("\n*** Entre com opção:\n\tP - Push\n\tO - Pop\n\tS - Seek");
		printf("\n\tT - Tamanho\n\tI - Imprimir\n\tX - Sair\n");

		scanf(" %c", &op);
		op = toupper(op);
		
		switch(op) {
		case 'P':
			printf("Inserindo dado: ");
			scanf( "%d", &dado );
			push( &minhaPilha, dado);
			break;
		case 'O':
			dado = pop( &minhaPilha );
			printf("Retirado: %d da pilha.\n", dado);
			break;
		case 'S':
			dado = peek( minhaPilha );
			printf("Cabeça da pilha: %d\n", dado);
			break;
		case 'T':
			printf("\nA pilha tem %d elementos.\n", size(minhaPilha));
			break;
		case 'I':
			imprimePilha(minhaPilha);
			break;
		case 'X':
			continua=0;
			break;
		}
	}
}
