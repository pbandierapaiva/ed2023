// Trabalhando com arquivos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cadastro.h"

int main(){

	FILE *fp;
	char linha[TAM_MAX];
	char primeiralinha[TAM_MAX];
	char campo[TAM_MAX];
	int tmax=0, tam=0;
	
	
	fp = fopen( "/home/pub/ed/UNIFESP.csv", "r" );
	if(!fp){
		printf("Erro de abertura de arquivo.\n");
		exit(-1);
		}
	
	
	fgets( primeiralinha, TAM_MAX, fp );
	while( fgets( linha, TAM_MAX, fp ) ) {
		if( pegaCampo(linha, NOME, campo) )
			if( ! strcmp( campo,"PAULO BANDIERA PAIVA" ) )
				for(int i=0;i<43;i++) {
					pegaCampo(primeiralinha, i, campo);
					printf("%s \t",campo);
					pegaCampo(linha, i, campo);
					printf("%s \n",campo);
					}
		}
		

		
		
		
	fclose(fp);


	return 0;
	}
