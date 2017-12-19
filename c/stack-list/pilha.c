#include "pilha.h"

Pilha* criaPilha(){
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->topo = NULL;
	return p;
}

int isEmpty(Pilha* p){
	return p->topo == NULL;
}

void push(Pilha* p, int n){
	No* novo = (No*) malloc(sizeof(No));
	novo->dado = n;

	novo->prox = p->topo;
	p->topo = novo;
	return;
}

int pop(Pilha* p){
	int info;
	No* aux;
	
	if(isEmpty(p)) return -1; //pilha vazia
	
	info = p->topo->dado;
	aux = p->topo;
	p->topo = p->topo->prox;
	free(aux);
	return info;
}
