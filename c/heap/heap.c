#include "heap.h"


#define PAI(i) (i/2)
#define FILHO_ESQ(i) (2*i)
#define FILHO_DIR(i) (2*i + 1)

void criaHeap(Heap *h){ //O(1)
	//cria heap definindo tamanho 0
	h->tamanho = 0;
	return;
}

void insereValor(Heap *h, int n){ //O(log n)
	int atual, aux;
	//insere na primeira folha livre
	h->tamanho++;
	atual = h->tamanho;
	h->array[atual] = n;
	//sobe checkando se as subheaps estão oks
	while(atual != 1){
		if(h->array[atual] < h->array[PAI(atual)]){
			//se for maior que o pai, troca os dois
			aux = h->array[atual];
			h->array[atual] = h->array[PAI(atual)];
			h->array[PAI(atual)] = aux;
			atual = PAI(atual);
		}else{
			//para se ela ja estiver satisfazendo a condicao de minHeap
			break;
		}
	}
	return;
}

int minValor(Heap h){ //O(1)
	//retorna o menor valor sem remover
	//antes olha para ver se a heap esta vazia
	//retorna -1 se estiver vazia
	return h.tamanho ? h.array[1] : -1;
}

int remove(Heap *h, int i){ //O(log n)
	//retorna -1 se estiver vazia ou nao existir o indice requisitado
	if(!h->tamanho || i > h->tamanho) return -1;

	int aux, removido = h->array[i];
	//troca o valor no indice atual pelo ultimo valor da heap, e diminui seu tamanho
	h->array[i] = h->array[h->tamanho];
	h->tamanho--;
	//desce trocando o atual pelo menor filho para manter a propriedade de heap
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

int removeMin(Heap *h){ //O(1)
	//chama o remove na posicao 1, menor valor da minHeap
	return remove(h, 1);
}

void imprimeHeap(Heap h){ //O(n)
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

