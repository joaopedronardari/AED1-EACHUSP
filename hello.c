#include <stdio.h>
#define ALTURAMAX 225
typedef struct $
{
	int peso;
	int altura;
}PA;

int main() {
	PA pessoa1;
	pessoa1.peso = 85;
	pessoa1.altura = 185;
	printf("Peso.: %d Altura.: %d", pessoa1.peso, pessoa1.altura);
	system("pause");
	return 0;
}
