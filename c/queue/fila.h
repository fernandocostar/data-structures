#ifndef FILA_H_
#define FILA_H_

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct fila{
	char elementos[MAX];
	int fim;
} Fila;

Fila create();
void push(Fila* f);
char pop(Fila* f);
int isEmpty(Fila p);
int isFull(Fila p);
int size(Fila p);

#endif