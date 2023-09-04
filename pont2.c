// Continuando a tabalhar com ponteiros


#include <stdio.h>
#define TAM_MAX 10

int main() {

	long int *p=NULL;
	
	long int va=1000;
	long int vb[TAM_MAX];
	
	printf("O endereço das variáveis va e vb: %ld %ld \n\n",(long int) &va,(long int) vb );
	
	p =  vb;
	for( int i=0; i<TAM_MAX; i++, p++)
		*p = 0;
	
	
	printf("Endereços do vetor: \n");
	p =  vb;
	for( int i=0; i<TAM_MAX; i++, p++)
		 printf("%d %ld \n", i, (long int) p );
	
	printf("Conteúdos do vetor: \n");	
	for( int i=0; i<TAM_MAX; i++) 
		printf(" %ld", vb[i] );


	printf("\n*** FIM *** \n");

	return 0;
}



