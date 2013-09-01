#include <stdio.h>
#define MAX 50
#define ERRO -1
#define true 1
#define false 0
typedef int bool; //dando um novo nome
typedef int TIPOCHAVE;
typedef struct {
	TIPOCHAVE chave;
}REGISTRO;
typedef struct $
{
	REGISTRO A[MAX+1]; //array de registros
	int numelem; //numero de elementos
}LISTA;

void exibir(LISTA* l) {
	int i;
	printf("Lista.: ");
	for (i=0;i<l->numelem;i++)
		printf("%d ", l->A[i].chave);
	printf("\n");
}

void inicializar(LISTA* l) {
	l->numelem = 0;
}

int tamanho(LISTA* l) {
	return l->numelem;
}

int tamanhoEmBytes(LISTA* l) {
	return sizeof(LISTA);
}

bool inserirOrdenado(REGISTRO reg,LISTA* l) {
	if(l->numelem == MAX) {
		return false;
	}

	int i = 0;
	TIPOCHAVE ch = reg.chave;
	l->A[l->numelem].chave = ch;
	
	while (l->A[i].chave < ch) i++;

	if ((l->A[i].chave == ch) && (i<l->numelem))
		return false;
	int x;
	for (x = l->numelem-1;x>=i;x--) { //VAI TROCANDO ELEMENTOS
		l->A[x+1] = l->A[x];
	}
	l->A[i] = reg; //COLOCA O NOSSO LA
	l->numelem++; //AUMENTA NUMERO DE ELEMENTOS ADICIONADOS
	return true;
}

int buscaBin(TIPOCHAVE ch,LISTA* l) {
	int esq,dir,meio;
	esq = 0;
	dir = l->numelem - 1;

	while(esq<=dir) {
		meio = (esq+dir)/2;
		if (l->A[meio].chave == ch) return meio;
		else {
			if (l->A[meio].chave >ch)
				dir = meio-1;
			else
				esq = meio+1;
		}
	}
	return ERRO;
}

bool excluirOrdenado(TIPOCHAVE ch,LISTA* l) {
	int pos,j;
	pos = buscaBin(ch,l);
	if (pos==ERRO) return false;
	for (j=pos;j<=l->numelem-2;j++) {
		l->A[j] = l->A[j+1];
	}
	l->numelem--;
	return true;
}

int main() {
	printf("HELLO");
	LISTA l;
	inicializar(&l);
		
	REGISTRO reg;
	reg.chave = 1;
	inserirOrdenado(reg,&l);
	reg.chave = 80;
	inserirOrdenado(reg,&l);
	reg.chave = 2332;
	inserirOrdenado(reg,&l);
	reg.chave = 2000;
	inserirOrdenado(reg,&l);
	reg.chave = 2000;
	inserirOrdenado(reg,&l);
	reg.chave = 43;
	inserirOrdenado(reg,&l);
	reg.chave = 1000000;
	inserirOrdenado(reg,&l);
	reg.chave = 54323;
	inserirOrdenado(reg,&l);

	printf("\nTAMANHO %d REGISTRO %d\n", tamanho(&l),reg.chave);
	exibir(&l);
	system("pause");
	return 0;
}
