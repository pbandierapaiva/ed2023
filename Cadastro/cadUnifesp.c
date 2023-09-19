// Trabalhando com arquivos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cadastro.h"

int main(){

	FILE *fp, *outfp;
	char linha[TAM_MAX];
	char campo[TAM_MAX];
	char *p, *q;
	
	CADBAS registro;
	
	
	fp = fopen( "/home/pub/ed/UNIFESP.csv", "r" );
	outfp = fopen( "RegUnifesp.dat", "w" );
	if(!fp ){
		printf("Erro de abertura de arquivo de entrada.\n");
		exit(-1);
		}
	if(!outfp ){
		printf("Erro de abertura de arquivo de saída.\n");
		exit(-1);
		}	
	
	q = (char *)&registro;
	
	fgets( linha, TAM_MAX, fp );
	while( fgets( linha, TAM_MAX, fp ) ) {
		// coloca 00 em todo o novo registro
		for( p = q; (p-q)<sizeof(registro); p++)
			*p=0;
		
		pegaCampo(linha, NOME, registro.Nome);
		pegaCampo(linha, DESCRICAO_CARGO, registro.DescCargo);		 
		pegaCampo(linha, UORG_LOTACAO, registro.uOrg);
		pegaCampo(linha, ORG_LOTACAO, registro.Org);
		pegaCampo(linha, ORGSUP_LOTACAO, registro.OrgSup);
		 
		fwrite( &registro, sizeof(registro), 1, outfp ); 
		}
	fclose(fp);
	fclose(outfp);


	return 0;
	}
