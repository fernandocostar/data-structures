#include "pilha.h"

Pilha* criaPilha(){
	Pilha* p = (Pilha*) malloc(sizeof(Pilha)); //aloca espaco pra pilha
	p->topo = NULL; //topo vazio
	return p;
}

int isEmpty(Pilha* p){
	return p->topo == NULL; //retorna topo se o topo esta vazio
}

void push(Pilha* p, int n){
	No* novo = (No*) malloc(sizeof(No)); //aloca memoria do no
	novo->dado = n; //guarda o dado
	//com a pilha vazia vamos setar prox como NULL(topo da pilha vazia) e mudar o novo topo
	//com a pilha cheia vamos setar o prox como o antigo topo e mudar o novo topo
	novo->prox = p->topo;
	p->topo = novo;
	return;
}

int pop(Pilha* p){
	int info;
	No* aux;
	
	if(isEmpty(p)) return -1; //pilha vazia
	//funciona para todos os casos
	//se houver um elemento setamos o topo como o prox do unico elemento (NULL), tornando a pilha vazia
	//se houverem mais elementos setamos o topo como o segundo elemento
	info = p->topo->dado;
	aux = p->topo;
	p->topo = p->topo->prox;
	free(aux);
	return info;
}
