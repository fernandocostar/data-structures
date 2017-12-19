#include "fila.h"

Fila* criaFila(){
	Fila* f = (Fila*) malloc(sizeof(Fila));
	f->inicio = NULL;
	f->fim = NULL;
}

int isEmpty(Fila* f){
	return f->inicio == NULL && f->fim == NULL;
}

void push(Fila* f, int n){
	No* novo = (No*) malloc(sizeof(No));
	novo->prox = NULL;
	novo->ant = NULL;
	novo->dado = n;

	if(isEmpty(f)){
		f->inicio = novo;
		f->fim = novo;
		return;
	}

	f->fim->prox = novo;
	novo->ant = f->fim;
	f->fim = novo;
	return;
}

int pop(Fila* f){
	int info;
	No* primeiro;
	No* segundo;

	if(isEmpty(f)) return -1;

	if(f->inicio == f->fim){
		info = f->inicio->dado;
		free(f->inicio);
		f->inicio = f->fim = NULL;
		return info;
	}

	primeiro = f->inicio;
	segundo = primeiro->prox;
	info = primeiro->dado;

	segundo->ant = NULL;
	f->inicio = segundo;
	free(primeiro);
	return info;
}