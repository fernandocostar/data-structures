#ifndef _pilha_h_
#define _pilha_h_

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int dado;
	struct no* prox;
}No;

typedef struct pilha{
	No* topo;
}Pilha;

Pilha* criaPilha();
void push(Pilha* p, int n);
int pop(Pilha* p);
int isEmpty(Pilha* p);

#endif