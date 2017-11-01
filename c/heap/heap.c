#include "heap.h"


#define PAI(i) (i/2)
#define FILHO_ESQ(i) (2*i)
#define FILHO_DIR(i) (2*i + 1)

void criaHeap(Heap *h){
	 //cria heap vazia onde o indice 0 não será utilizado
	h->tamanho = 0;
	return;
}

void insereValor(Heap *h, int n){
	int altura, aux;
	//insere na primeira folha livre
	h->tamanho++;
	altura = h->tamanho;
	h->array[altura] = n;
	//sobe checkando se as subheaps estão oks
	while(altura){
		if(h->array[altura] < h->array[altura/2]){
			aux = h->array[altura];
			h->array[altura] = h->array[altura/2];
			h->array[altura/2] = aux;
			altura /= 2;
		}else{
			break;
		}
	}
	return;
}

int minValor(Heap h){
	if(h.tamanho)return h.array[1];
}

void imprimeHeap(Heap h){
	if(!h.tamanho){
		int i;
		printf("%d", h.array[1]);
		for(i = 2; i <= h.tamanho; i++){
			printf(" %d", h.array[i]);
		}
		printf("\n");
		return;
	}
	printf("\n");
	return;
}

