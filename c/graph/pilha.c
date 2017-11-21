#include "pilha.h"

Pilha criaPilha() {
	Pilha p;
	p.topo = -1;
	return p;
}

int pilhaVazia(Pilha p) {
	return (p.topo == -1);
}

void pushPilha(Pilha *p, int x) {
	p->topo++;
	p->vetor[p->topo] = x;
	return;
}

int popPilha(Pilha *p) {
	int x = p->vetor[p->topo];
	p->topo--;
	return x;
}

