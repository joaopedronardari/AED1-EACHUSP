#include <stdio.h>
#include <malloc.h>

int main() {
	int n = 10; //10 elementos no array !
	int* v = (int*) malloc(sizeof(int) * n);
	printf("ENDERECO NA MEMORIA.: %d \n", v);

	int i; //for nao aceita criar variaveis diretamente

	for (i = 0; i<n;i++) {
		v[i] = i+1;
		printf("%d\n\n",v[i]);
	}

	int* pos = v;
	for (i = 0;i<n;i++) {
		printf("posicao.: %ld, valor: %d \n", pos, *pos);
		pos++;
	}
	return 0;
}
