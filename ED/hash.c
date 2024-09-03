// Função de dispersão
//
//
#include <stdio.h>
#include <stdlib.h>

#define MAX_TABLE 1000000

long int hash(const char * str) {
	int h = 401;
	int c;

	while (*str != '\0') {
		h = ((h << 4) + (int)(*str)) % MAX_TABLE;
		str++;
	}

	return h % MAX_TABLE;
}

int main() {

	char inp[200];

	while(1) {
            fgets(inp, 200, stdin);
        	printf("%ld\n",hash(inp));
	}
}