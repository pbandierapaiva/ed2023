// Trbalhando com matrizes e alocação dinâmica

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *criaMat(char *seq1, char *seq2) {
    int *m = NULL;
    int ncol,nlin;
    char cara;

    ncol = strlen(seq1);
    nlin = strlen(seq2);
    m = malloc( sizeof(int) * ncol * nlin );
    if(!m) return NULL;

    for(int i=0; i<ncol; i++) {         // colunas ou seq1
        for(int j=0; j<nlin; j++) {     // linhas ou seq2
            if(seq1[i]==seq2[j])
                cara = '*';
            else
                cara = ' ';

            m[ i*ncol + j ] = cara;     // m[i][j]
        }
    }
    return m;
}

void imprimeMat(int *m, char *s1, char *s2){
    int nlin,ncol;

    ncol= strlen(s1);
    nlin= strlen(s2);

    printf("\n %s",s1);

    for(int i=0; i<nlin; i++) {
        printf("\n%c",s2[i]);
        for(int j=0;j<ncol; j++){
            printf("%c", m[j*ncol + i]);
        }
    }
}


int main() {
    FILE *fp;

    int *mat = NULL;
    char s1[10000],s2[10000];
    int tam1=0, tam2=0;
    char linha[100];
    char *ptr;
    char c;

    fp = fopen("exemplo.fas","r");
    if( !fp ) {
        printf("Erro de abertura de arquivo.\n\n");
        exit(1);
    }

    do {
        c = fgetc(fp);
    } while(c!='>' && !feof(fp) );

    if(feof(fp)) exit(1);

    while(fgetc(fp)!='\n');  // descrição da 1a sequencia
    ptr = s1;
    do {
        c = fgetc(fp);
        if( c!='\n' && c !='>') {
            *ptr = c;
            ptr++;
            tam1++;
        } 
    } while(c!='>');
    while(fgetc(fp)!='\n');
    ptr = s2;
    do {
        c = fgetc(fp);
        if(feof(fp)) break;
        if( c!='\n' && c !='>') {
            *ptr = c;
            ptr++;
            tam2++;
        } 
    } while(c!='>' && !feof(fp));

    s1[tam1]='\0';
    s2[tam2]='\0';

    printf("%s\n---\n%s \nTam1: %d Tam2: %d\n", s1, s2, tam1, tam2);

    if(strcmp(s1,s2)==0)
        printf("\nAs sequências são iguais.\n");

    mat = criaMat(s1,s2);
    imprimeMat(mat, s1, s2);
 }

