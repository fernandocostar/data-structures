#include "pilha.h"
#include <stdlib.h>

Fila create(){
	Fila* f = (Fila*) malloc(Fila);
	f -> fim = -1;
	return (*f);  
}

void push(Fila* f, char c){
	if((*f).fim != 99){
		f -> fim++;
		(*f).elementos[(*f).fim] = c;
	return;
	}
	printf("Queue full.\n");
	exit(-1);
}

char pop()