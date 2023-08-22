
#include <stdio.h> 

int main() {
    int i=0;
    unsigned int u;
    short int s;
    long int l;
    float f;
    double d;

    u = -6;
    s = 10000;
        
    printf("Tamanho do inteiro i: \t%d\tvalor: %d\n" ,sizeof(i), i);
    printf("Tamanho do inteiro sem sinal u: \t%d\tvalor: %u\n" ,sizeof(u), u);
    printf("Tamanho do inteiro curto s: \t%d\tvalor: %d\n" ,sizeof(s), s);
    printf("Tamanho do long int l: \t%d\n" ,sizeof(l));
    printf("Tamanho do float f: \t%d\n" ,sizeof(f));
    printf("Tamanho do double d: \t%d\n" ,sizeof(d));
    printf("\n");
}
