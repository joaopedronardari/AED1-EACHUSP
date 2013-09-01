#include <stdio.h>
#include <malloc.h>
#define true 1
#define false 0
typedef int bool;
typedef int TIPOCHAVE;
typedef struct aux {
	TIPOCHAVE chave;
	struct aux* prox;
}REGISTRO,* Pont;
typedef struct {
	Pont inicio;
}Lista;

void inicializar (Lista* l) {
	l->inicio = NULL;
}

int tamanho (Lista l) {
	Pont p = l.inicio;
	int cont = 0;
	while(p!=NULL) {
		cont++;
		p = p->prox;
	}
	return cont;
}

int tamanhoEmBytes(Lista* l) {
	return sizeof(LISTA); //DUVIDA CHECAR DEPOIS
}

Pont buscaSeqExc(TIPOCHAVE ch,Lista* l,Pont* ant) {
	*ant = NULL;
	Pont p = l->inicio;
	while ((p!=NULL) && (p->chave<ch)) {
		*ant = p;
		p = p->prox;
	}
	if ((p!=NULL) && (p->chave == ch)) {
		return p;
	}
	return NULL;
}

bool excluir(TIPOCHAVE ch, Lista* l) {
	Pont ant,i;
	i = buscaSeqExc(ch,l,&ant);
	if (i!=NULL) {
		if(ant==NULL)
			l->inicio = i->prox;
		else
			ant->prox = i->prox;
		free i;
		return true;
	}
	return false;
}

bool inserir (REGISTRO reg, Lista* l) {
	Pont ant,i;
	i=buscaSeqExc(reg.chave,l,&ant);
	if(i!=NULL)
		return false;
	i = (Pont) malloc(sizeof(REGISTRO));
	*i = reg;
	if (ant == NULL) {
		i->prox = l->inicio;
		l->inicio=i;
	}
	else {
		i->prox = ant->prox;
		ant->prox = i;
	}
	return true;
}

void destruir(Lista* l) {
	Pont p,apagar;
	p = l->inicio;
	while (p!=NULL) {
		apagar = p;
		p = p->prox;
		free apagar;
	}
	l->inicio = NULL;
}
