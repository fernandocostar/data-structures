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
			case 'M':
				printf("%d\n", minValor(h));
				break;
			case 'P':
				imprimeHeap(h);
				break;
		}
		scanf(" %c", &op);
	}
	return 0;
}