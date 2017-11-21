#include "grafo.h"

int main(){
	int n, entrada_1, entrada_2;
	scanf("%d", &n);

	Grafo g = criaGrafo(n);

	scanf("%d", &entrada_1);
	scanf("%d", &entrada_2);
	while(entrada_1 != -1 && entrada_2 != -1){

		insereAresta(&g, entrada_1, entrada_2);

		scanf("%d", &entrada_1);
		scanf("%d", &entrada_2);
	}
	scanf("%d", &entrada_1);
	buscaLargura(g, entrada_1);
	buscaProfundidade(g, entrada_1);
	return 0;
}