// Testa gerador de números aleatórios
//
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(){
	int tam=17;
	
	srandom(time(NULL));
	for( int i=0; i<tam; i++)
		printf("%d\n",  (int) ( tam * (random() / (pow(2,31))))) ;
	}




