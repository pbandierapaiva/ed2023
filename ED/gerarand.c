#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct  listaS {
	int carga;
	struct listaS *prox;
} ListaSE;

int sorteia(int max) {
	return random()%max;
	}
	
int main() {
	int n;
	int max;
	
	printf("Entre com N: ");
	scanf("%d", &n);
	printf("Entre com MAX: ");
	scanf("%d", &max);
	
	for(int i=0; i<n; i++){
		printf("%d ", sorteia(max));
		}
	}

