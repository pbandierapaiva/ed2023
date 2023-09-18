/* Programa para calcular a média de uma série de números */
#include <stdio.h>
#include <math.h>

#define  TAM_MAX 10


int main() {
    int n;
    float num;
    float soma=0, media=0;
    
    float vetor[TAM_MAX];

    printf("Quantos números em sua série? ");
    scanf("%d", &n);

    if( n > TAM_MAX ){
        printf("O número máximo de elementos é %d\n", TAM_MAX);
        return 0;
    }
    
    printf("Entrando %d valores:\n", n);
    for( int conta=0; conta<n ; conta++) { 
        printf("%d > ", conta+1);
        scanf("%f", &num);
        vetor[conta] = num;
        soma = soma + num;
    }
    printf("A soma total é %f\n", soma);
    media = soma/n;
    printf("A média aritimética é %.2f \n\n", media);
    
    // calculando desvio-padrão
    soma=0;
    for( int i=0; i<n; i++ ){
           soma += (vetor[i]-media)*(vetor[i]-media);
    }
    printf("O desvio padrão populacional é %.2f\n", sqrt( soma / n ) );
    printf("O desvio padrão amostral é %.2f\n\n", sqrt( soma / (n-1) ) );

    return 0;
    
    
}
