// Definições para o programa que lê cadastro

#define TAM_MAX 1000

#define Id_SERVIDOR_PORTAL	0
#define NOME			1
#define CPF			2
#define MATRICULA		3
#define DESCRICAO_CARGO		4
#define CLASSE_CARGO		5
#define REFERENCIA_CARGO	6
#define PADRAO_CARGO		7
#define NIVEL_CARGO		8
#define SIGLA_FUNCAO		9
#define NIVEL_FUNCAO		10
#define FUNCAO			11
#define CODIGO_ATIVIDADE	12
#define ATIVIDADE		13
#define OPCAO_PARCIAL		14
#define COD_UORG_LOTACAO	15
#define UORG_LOTACAO		16
#define COD_ORG_LOTACAO		17
#define ORG_LOTACAO		18
#define COD_ORGSUP_LOTACAO	19
#define ORGSUP_LOTACAO		20
#define COD_UORG_EXERCICIO	21
#define UORG_EXERCICIO		22
#define COD_ORG_EXERCICIO	23
#define ORG_EXERCICIO		24
#define COD_ORGSUP_EXERCICIO	25
#define ORGSUP_EXERCICIO	26
#define COD_TIPO_VINCULO	27
#define TIPO_VINCULO		28
#define SITUACAO_VINCULO	29
#define DATA_INICIO_AFASTAMENTO	30
#define DATA_TERM_AFASTAMENTO	31
#define REGIME_JURIDICO		32
#define JORNADA_DE_TRABALHO	33
#define DATA_ING_CARGOFUNCAO	34
#define DATA_NOM_CARGOFUNCAO	35
#define DATA_INGRESSO_ORGAO	36
#define DOC_ING_SERVICOPUBLICO	37
#define DATA_DIP_ING_SERVPUB	38
#define DIPLOMA_ING_CARGOFUNCAO	39
#define DIPLOMA_ING_ORGAO	40
#define DIPLOMA_ING_SERVPUB	41
#define UF_EXERCICIO		42


typedef struct {
	char Nome[100];
	char DescCargo[50];
	char uOrg[100];		// UORG_LOTACAO
	char Org[100];		// ORG_LOTACAO
	char OrgSup[100];		// ORGSUP_LOTACAO
} CADBAS;


typedef struct {
	char Nome[100];
	long int posicao;
} CADIND;

typedef struct ListaCadInd {
	CADIND cadind;
	struct ListaCadInd *prox;
} LISTACADIND;

typedef struct no {
	CADIND carga;	

	struct no *noE;
	struct no *noD;
	} NOCAD;


// Protótipos de funções
int pegaCampo(char *, int, char *);
void pegaReg(CADBAS *, char *);
void imprimeReg(CADBAS );
















