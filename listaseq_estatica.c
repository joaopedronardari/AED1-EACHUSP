#include <stdio.h>
#define MAX 50
#define NUL -1
#define true 1
#define false 0
typedef int bool;
typedef int TIPOCHAVE;
typedef struct {
	TIPOCHAVE chave;
	int prox;
}REGISTRO;
typedef struct{
	REGISTRO A[MAX];
	int inicio;
	int dispo;
}LISTA;

void inicializar(LISTA* l) {
	//COLOCA -1 em todas as posicoes
	l->inicio = NUL;
	l->dispo = 0;
	int i;
	for (i = 0; i<MAX-1;i++) {
		l->A[i].prox = i+1;
	}
	l->A[MAX-1].prox = NUL;
}

int tamanho(LISTA* l) {
	int c = 0;
	int p = l->inicio;
	while(p!=NUL) {
		c++;
		p=l->A[p].prox;
	}
	return c;
}

int tamanhoEmBytes(LISTA* l) {
	return sizeof(LISTA);
}

int buscaSeq(TIPOCHAVE c,LISTA* l,int* ant) { //AGORA SEI O ANT É O ANTERIOR kkk JOAO PEDRO PRESTA ATENCAO CARA!
	*ant = NUL;
	int p = l->inicio;
	while((p!=NUL) && (l->A[p].chave<c)) {
		*ant = p;
		p = l->A[p].prox;
	}
	if ((p!=NUL) && (l->A[p].chave == c))
		return p;
	else
		return NUL;
}

bool excluir (TIPOCHAVE ch, LISTA* l) {
	int ant,i;
	i = buscaSeq(ch,l,&ant);
	if (i==NUL) return false;
	if (ant == NUL)
		l->inicio = l->A[i].prox;
	else 
		l->A[ant].prox = l->A[i].prox;

	l->A[i].prox = l->dispo;
	l->dispo = i;
	return true;
}

bool inserirOrd(REGISTRO reg, LISTA* l) {
	if (l->dispo == NUL) return false;
	int ant,i;
	i = buscaSeq(reg.chave,l,&ant);
	if (i!=NUL) return false;
	i = l->dispo;
	l->dispo = l->A[l->dispo].prox;
	l->A[i] = reg;
	if (ant == NUL) {
		l->A[i].prox = l->inicio;
		l->inicio = i;
	}
	else {
		l->A[i].prox = l->A[ant].prox;
		l->A[ant].prox = i;
	}
	return true;
}

