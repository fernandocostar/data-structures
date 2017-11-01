#ifndef _HEAP_H_
#define _HEAP_H_

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct heap{
	int array[MAX+1];
	int tamanho;
}Heap;

void insereValor(Heap *h, int n);
int minValor(Heap h);
void criaHeap(Heap *h);
void imprimeHeap(Heap h);

#endif
