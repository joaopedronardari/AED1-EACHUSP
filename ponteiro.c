#include <stdio.h>
#include <malloc.h>

typedef struct {
	int peso;
	int altura;
}PA;
typedef PA* pont; //ponteiro para PA chamara pont
int main() {
	pont pessoa1 = (pont) malloc(sizeof(PA));
	pessoa1->peso = 85;
	pessoa1->altura = 185;
	PA pessoa2;
	pessoa2.peso = 110;
	pessoa2.altura = 300;

	pessoa1 = &pessoa2;
	printf("PESO %d ALTURA %d", pessoa1->peso, pessoa1->altura);
	return 0;
}
