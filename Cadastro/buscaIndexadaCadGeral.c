// Programa que faz busca no Cadastro Geral de Servidores

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "cadastro.h"

int main( int argc, char *argv[] ){

	FILE *fp, *indfp;

	char linha[TAM_MAX];
	char nome[100];
	char nlido[100];
	char *p;
	int contador=0;
	int regInteresse;
	int maxRegs = 10;
	
	CADBAS reg;
	CADIND regind;
	
	CADIND *resultado;
	
	printf("Executando busca indexada no arquivo.\n");
	if( argc < 2 ){
		printf("Entre com nome para busca: ");
		fgets(nome, 100, stdin);
		}
	else {
		strcpy(nome, argv[1]);
		}	
	
	// remove \n do final do string
	for( p = nome; *p!='\n' && *p!='\0'; p++)
		*p = toupper(*p);
	*p = '\0';	

// Busca indexada no cadastro		
	fp = fopen( "/home/pub/ed/Cadastro.csv", "r" );
	indfp = fopen( "Cadastro.ind", "r" );
	if(!fp || !indfp){
		printf("Erro de abertura de arquivo.\n");
		exit(-1);
		}

	resultado = malloc( maxRegs * sizeof(CADIND) );
	while( fread( &regind, sizeof(regind), 1, indfp ) ){
		if( strstr(regind.Nome, nome) ) {
			if( contador == maxRegs ){
				maxRegs += 10;
				resultado = realloc(resultado, maxRegs*sizeof(CADIND));
				if(!resultado){
					printf("\nErro de alocação de memória\n");
					return -1;
					}
				}
			resultado[contador] = regind;
			contador+=1;			
			}
		}
	
	if(!contador) {
		printf("\nNenhum registro encontrado\n");
		return 0;
		}
	
	if( contador==1 ) {
		regInteresse=1;
		}
	else {
		printf("\nRegistros encontrados: \n");
		for( int i=0; i<contador; i++) {
			printf("%d %s\n", i+1, resultado[i].Nome);
			}
		printf("\nEntre com o número do registro de interesse: \n");
		scanf( "%d", &regInteresse );
		}
	if( regInteresse<=0 || regInteresse>contador ){
		printf("\nRegistro inválido\n");
		return 0;
		}
	
		
	fseek( fp, resultado[regInteresse-1].posicao, 0 );
	fgets( linha, TAM_MAX, fp );
	pegaReg( &reg, linha );
	imprimeReg( reg );




	fclose(fp);
	fclose(indfp);

	return 0;
	}
