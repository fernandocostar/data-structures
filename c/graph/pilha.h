#include <stdio.h>

#define MAX_P 100

typedef struct pilha {
	int topo;
	int vetor[MAX_P];
} Pilha;

Pilha criaPilha();
int pilhaVazia(Pilha p);
void pushPilha(Pilha *p, int x);
int popPilha(Pilha *p);
