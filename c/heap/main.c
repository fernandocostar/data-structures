#include "heap.h"

int main(){
	int k;
	char op;
	Heap h;
	criaHeap(&h);
	scanf(" %c", &op);
	while(op != 'S'){
		switch(op){
			case 'I':
				scanf("%d", &k);
				insereValor(&h, k);
				break;
			case 'T':
				printf("Valor do topo: %d\n", minValor(h));
				break;
			case 'P':
				imprimeHeap(h);
				break;
			case 'R':
				scanf("%d", &k);
				printf("Removido: %d\n", removeAt(&h, k));
				break;
			case 'M':
				printf("Minimo removido: %d\n", removeMin(&h));
				break;
		}
		scanf(" %c", &op);
	}
	return 0;
}