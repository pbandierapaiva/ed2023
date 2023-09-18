// Trabalhando com strings 

#include <stdio.h>

void troca(int *pA, int *pB){
	int tmp;
	
	tmp = *pA;
	*pA = *pB;
	*pB = tmp;
	
	printf("Na função troca>>> Endereço de a: %ld, de b: %ld\n", 
		(long int)pA,(long int) pB);

}

int main() {
	int a,b;
	printf("Entre com dois números: ");
	scanf("%d %d", &a, &b);

	troca(&a, &b);	

	printf("Na função main>>> Endereço de a: %ld, de b: %ld\n",
		(long int) &a,(long int) &b);
	


	return 0;	
}













