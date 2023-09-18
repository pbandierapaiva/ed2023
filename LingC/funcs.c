// Trabalhando com strings 

#include <stdio.h>



void funcao(int paramA, int paramB){
	
	printf("Recebi %d e %d e a soma é %d\n\n",paramA,paramB,paramA+paramB);
	return;
}

int fatorial(int n){
	int i=1;
	int result=1;
	
	for(i=n;i>1;i--)
		result = result*i;
	return result;
}

int main() {
	int a,b;
	printf("Entre com dois números: ");
	scanf("%d %d", &a, &b);
	funcao(a,b);
	
	printf("O número %d fatorial é: %d\n", a, fatorial(a));
	
	return 0;
}










