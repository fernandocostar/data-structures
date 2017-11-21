#include "fila.h"

Fila criaFila() {
	Fila f;
	f.inicio = 0;
	f.fim = 0;
	return f;
}

int filaVazia(Fila f) {
	return (f.fim == f.inicio);
}

void pushFila(Fila *f, int x) {
	f->vetor[f->fim] = x;
	f->fim = (f->fim+1) % MAX_F;
	return;
}

int popFila(Fila *f) {
	int x = f->vetor[f->inicio];
	f->inicio = (f->inicio+1) % MAX_F;
	return x;
}

