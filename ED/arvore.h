// arvore.h

typedef struct no {
	int carga;	

	struct no *noE;
	struct no *noD;
	} NO;

void insere( NO **, int  );
NO *checaAVL( NO * );
void insereAVL( NO **, int  );
int altura( NO * );
int fb( NO * );
NO *pai( NO *, NO * );
void balanceiaAVL( NO **);

void rotacaoDireita( NO ** );
void rotacaoEsquerda( NO ** );
void rotacaoDuplaDireita( NO ** );
void rotacaoDuplaEsquerda( NO ** );

