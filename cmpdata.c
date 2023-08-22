//
//  Calcula qual data é a maior
//


#include <stdio.h>

int main(){
    int d1,m1,a1,d2,m2,a2;
    int d1maior = 0, d2maior = 0;
    
    printf("Entre com a data 1 no formato \"dia mês ano\"\n");
    scanf("%d %d %d",&d1,&m1,&a1);
    printf("\nEntre com a data 2\n");
    scanf("%d %d %d",&d2,&m2,&a2);
    
    if( a2>a1 )
        d2maior=1;
    else if( a1>a2 )
        d1maior=1;
    else if( m2>m1 )
        d2maior=1;
    else if( m1>m2 )
        d2maior=1;
    else if( d2>d1 )
        d2maior=1;
    else if( d1>d2 )
        d2maior=1;
    
    if(d1maior)
        printf("A data 1 é maior\n");
    else if(d2maior)
        printf("A data 2 é maior\n");
    else
        printf("As datas são iguais\n");
        
    
    return 0;
}

