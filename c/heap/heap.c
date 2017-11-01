#include "heap.h"


#define PAI(i) (i/2)
#define FILHO_ESQ(i) (2*i)
#define FILHO_DIR(i) (2*i + 1)

void criaHeap(Heap *h){
	h->tamanho = 0;
	return;
}

void insereValor(Heap *h, int n){
	int atual, aux;
	//insere na primeira folha livre
	h->tamanho++;
	atual = h->tamanho;
	h->array[atual] = n;
	//sobe checkando se as subheaps estão oks
	while(atual != 1){
		if(h->array[atual] < h->array[PAI(atual)]){
			aux = h->array[atual];
			h->array[atual] = h->array[PAI(atual)];
			h->array[PAI(atual)] = aux;
			atual = PAI(atual);
		}else{
			break;
		}
	}
	return;
}

int minValor(Heap h){
	if(h.tamanho)return h.array[1];
}

int remove(Heap *h, int i){
	if(!h->tamanho) return -1;
	int aux, removido = h->array[i];
	h->array[i] = h->array[h->tamanho];
	h->tamanho--;

	while(h->array[i] > h->array[FILHO_DIR(i)] || h->array[i] > FILHO_DIR(i)){
		if(h->array[FILHO_DIR(i)] <= h->array[FILHO_ESQ(i)]){
			aux = h->array[FILHO_DIR(i)];
			h->array[FILHO_DIR(i)] = h->array[i];
			h->array[i] = aux;
		}else{
			aux = h->array[FILHO_ESQ(i)];
			h->array[FILHO_ESQ(i)] = h->array[i];
			h->array[i] = aux;
		}
	}
	return removido;
}

int removeMin(Heap *h){
	return remove(h, 1);
}

void imprimeHeap(Heap h){
	if(h.tamanho){
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

