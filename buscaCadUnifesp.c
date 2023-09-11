// Trabalhando com arquivos
// utiliza arquivo estruturado (com estrutura do registro CADBAS
// para pesquisar no arquivo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cadastro.h"

int main(){

	FILE *fp;
	CADBAS reg;
	char nome[100];
	char *p;
	
	fp = fopen( "RegUnifesp.dat", "r" );
	if(!fp){
		printf("Erro de abertura de arquivo.\n");
		exit(-1);
		}
	printf("Entre com nome para busca: ");
	fgets(nome, 100, stdin);
	// remove \n do final do string
	for( p = nome; *p!='\n' && *p!='\0'; p++);
	*p = '\0';
		
	while( fread( &reg, sizeof(reg), 1, fp ) ) {
		if( ! strcmp( reg.Nome, nome) ){
			printf("\n\nNome: %s\nCargo: %s\nUORG: %s\nORG: %s\nORGSUP: %s\n\n",
				reg.Nome, reg.DescCargo, reg.uOrg, reg.Org, reg.OrgSup );
			}
		}
	fclose(fp);
	return 0;
	}
