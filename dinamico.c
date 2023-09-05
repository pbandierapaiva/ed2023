// Exemplo de alocação dinâmica de memória

#include <stdio.h>
#include <stdlib.h>

int main(){
	long int tam=0;
	float *p;
	
	printf("Quantos elementos? ");
	scanf( "%ld", &tam );
	
	printf("Alocando espaço para %ld elementos\n", tam );
		
	p = malloc(  tam * sizeof(float)  );
	if(!p) {  // p == NULL - ocorreu um erro de alocação
		printf("Falha na alocação de memória.\n");
		return(-1);
	}

	for( long int i=0; i<tam; i++ ) {
		scanf("%f", &(p[i]) );
	}
	
	for( long int i=0; i<tam; i++ ) 
		printf("\n%ld %f", i, p[i]);
	
	printf("\n"); 

	// Liberando memóra alocada
	free(p);

	return 0;
}


