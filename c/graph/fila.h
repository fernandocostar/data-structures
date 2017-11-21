#include <stdio.h>

#define MAX_F 100

typedef struct fila {
	int inicio;
	int fim;
	int vetor[MAX_F];
} Fila;

Fila criaFila();
int filaVazia(Fila f);
void pushFila(Fila *f, int x);
int popFila(Fila *f);
