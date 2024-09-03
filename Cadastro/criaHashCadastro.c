/*
* Programa: hash.c
* 
* Implementa hash
*  
*/

#define TAMHASH 65536

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "cadastro.h"

// Algoritmo simples de hash
unsigned int hash(const char *key, unsigned int size)
{
	int hash = 401;
	int c;

	while (*key != '\0') {
		hash = ((hash << 4) + (int)(*key)) % size;
		key++;
	}

	return hash % size;

}

// Algoritmo mais simples de hash!
unsigned int hash0(const char *key, unsigned int size)
{
	unsigned int i;
	unsigned int hash = 0;
	/*loop through all the chars*/
	for ( i=0 ; key && key[i] ; i++ )
		{
		/*add all the ASCIIs*/
		hash += key[i];
		}
	/*convert hash code to fit it inside the range*/
	hash = hash % size;
	return hash;
}

// Estrutura para armazenar Baldes de ítens (item = nome+ localização no arquivo CSV)
typedef struct BALDE {
	char nome[300];			// DADOS
	unsigned long int local;	// _______
	struct BALDE *prox;		// ponteiro para próximo
} Balde;

// Insere dado numa estrutura de dados Balde
void insereBalde(char *chave, unsigned long loc, Balde **balde) {
	Balde *novoNo;
	
	novoNo = malloc( sizeof(Balde) );
	strcpy( novoNo->nome,chave );
	novoNo->local = loc;
	novoNo->prox = NULL;
	
	if( *balde == NULL ) 
		*balde = novoNo;
	else {
		novoNo->prox = *balde;
		*balde = novoNo;
		}
	}

// Retorna o número de ítens no balde
int tamBalde(  Balde *balde ){
	int conta=0;
	Balde *tmp;
	
	tmp = balde;
	
	while( tmp != NULL ) {
		conta++;
		tmp = tmp->prox;
		}
	return conta;
	}


// Lê arquivo CSV e coloca referências aos dados em duas tabelas de dispersão construídas
// usando diferentes algoritmos.
// Salva um CSV com o número de itens em cada balde usando as duas funções de dispersão. 
int main() {
	int i;
    long int posicaoCSV;
	FILE *entra; //, *sai;
	char linha[TAM_MAX];
	char nome[TAM_MAX];

	// Criação das hash tables, uma para cada agoritmo de hash
	Balde *hashtable[TAMHASH],  *hash0table[TAMHASH];	
	for( i=0; i<TAMHASH; i++) {
		hashtable[i]=NULL;
		hash0table[i]=NULL;
		}
	
	entra = fopen("/home/pub/ed/Cadastro.csv", "r");
	if( !entra ) {
		printf("\nErro de abertura de arquivo\n\n");
		return -1;
		}	
		
	printf("Lendo arquivo...\nConstruindo tabela de dispersão com %d baldes\n",TAMHASH);
	i=0;
	while( ! feof(entra) ){
        posicaoCSV = ftell(entra);
		fgets( linha, TAM_MAX, entra );
		pegaCampo( linha, NOME, nome );   // extrai da linha o campo nome
		
		// na tabela de dispersão "hashtable", acesso o índice retornado pela função "hash" ou "hash0" 
		insereBalde( nome, posicaoCSV, &( hashtable[ hash( nome, TAMHASH ) ]) ) ;    
		insereBalde( nome, posicaoCSV, &( hash0table[ hash0( nome, TAMHASH ) ]) ) ;
		}
	
	fclose(entra);
	
	// Como se dispersam os dados nas tabelas de dispersão?
	// Conta quantos itens em cada balde
	FILE *out;
	char filename[40];

	sprintf(filename, "results_hash_%d.csv", TAMHASH);	
	out = fopen(filename,"w");  // tabelas de tamanho TAMHASH
	
	fprintf( out, "i,comhash,comhash0\n");	
	for(i=0; i< TAMHASH; i++) {
		fprintf(out, "%d,%d,%d\n", i, tamBalde(hashtable[i]), tamBalde(hash0table[i]) );
	}
	fclose(out);
	return 0;
}	
	



