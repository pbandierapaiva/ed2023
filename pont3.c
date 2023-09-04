// Continuando a tabalhar com ponteiros...


#include <stdio.h>
#define TAM_MAX 1000

int main() {
	char s[TAM_MAX];
	char *p;
	int conta=0;
	int temLetra=0;
	
	printf("\nEntre com string: ");
	fgets( s, TAM_MAX, stdin);
	printf("\nString lido:\n%s", s);
	
	// Imprime string invertido
	for(p = s; *p != '\0' ; p++);
	for( p--; p>=s; p--) putchar( *p );	
	putchar('\n');
	
	// Conta palavras
	p = s;
	while(*p!='\0' && *p!='\n' ) {
		while( *p!=' ' && *p!='\0' ) {
			temLetra=1;
			p++;
			}
		while( *p==' ' && *p!='\0' ) 
			p++;
		if(temLetra==1) 
			conta++;
		}
	printf("O número de palavras na string é: %d\n\n", conta);

	return 0;
}
