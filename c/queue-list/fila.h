#ifndef _fila_h_
#define _fila_h_

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int dado;
	struct no* prox;
	struct no* ant;
}No;

typedef struct fila{
	No* inicio;
	No* fim;
}Fila;

Fila* criaFila();
void push(Fila* f, int n);
int pop(Fila* f);
int isEmpty(Fila* f);

#endif