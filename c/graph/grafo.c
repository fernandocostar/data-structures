#include "grafo.h"
#include "pilha.h"
#include "fila.h"

//funcao retorna um tad de grafo
Grafo criaGrafo(int n){
	int i;
	//cria ponteiro para uma estrutura de grafo
	Grafo* g = (Grafo*) malloc(sizeof(Grafo));
	//cria uma lista de ponteiros que apontam para as listas de adjacencia
	g->lista = (No**) malloc(sizeof(No*)*n);
	//guarda o inicio de cada uma das listas, sendo cada noh um dos vertices do grafo (0 a n-1)
	for(i = 0; i < n; i++){
		No* n = (No*) malloc(sizeof(No)); //alocando espaco de um no da lista ligada
		n->vert = i; //define o vertice
		n->prox = NULL; //proximo = NULL -> lista vazia
		g->lista[i] = n; //guarda o ponteiro no array de ponteiros do grafo
	}
	return (*g); //retorna o tad apontado pelo ponteiro de grafo
}

void insereAresta(Grafo *g, int v, int u){
	//cria um noh auxiliar com o valor de vertice v
	No* copia_v = (No*) malloc(sizeof(No));
	copia_v->vert = v;
	copia_v->prox = NULL;
	
	//cria um noh auxiliar com o valor de vertice u
	No* copia_u = (No*) malloc(sizeof(No));
	copia_u->vert = u;
	copia_u->prox = NULL;

	//cria um noh auxiliar que contem o inicio da lista ligada do vertice v
	No* aux = g->lista[v];
	while(aux->prox) aux = aux->prox;
	aux->prox = copia_u; //coloca u como sendo o ultimo da lista ligada de v

	//cria um noh auxiliar que contem o inicio da lista ligada do vertice v
	aux = g->lista[u];
	while(aux->prox) aux = aux->prox;
	aux->prox = copia_v; //coloca v como sendo o ultimo da lista ligada de u

	return;
}

void buscaLargura(Grafo g, int s){
	int visitados[MAX] = {0}; //cria array de vertices visitados com todos nao visitados
	int vertice;
	Fila f = criaFila();
	
	pushFila(&f, s); //insere o vertice source na fila
	visitados[s] = 1; //marca como visitado

	printf("Busca em Largura:");
	printf(" %d", s);

	while(!filaVazia(f)){ //enquanto a filha tiver algum elemento
		vertice = popFila(&f); //retira esse elemento
		No* noh = g.lista[vertice]; //pega o inicio da lista de arestas desse vertice
		while(noh->prox){ //percorre a lista
			noh = noh->prox;
			if(!visitados[noh->vert]){ //se um dos vertices adjacentes nao tiver sido visitado
				pushFila(&f, noh->vert); //coloca na fila
				visitados[noh->vert]++; //marca como visitado
				printf(" %d", noh->vert); //imprime o vertice
			}
		}
		//repete o procedimento efetuando uma busca em largura
	}
	printf("\n");
	return;
}

void buscaProfundidade(Grafo g, int s){
	int visitados[MAX] = {0}; //cria array de vertices visitados com todos nao visitados
	int vertice;
	Pilha p = criaPilha();

	pushPilha(&p, s); //insere o vertice source na pilha

	printf("Busca em Profundidade:");

	while(!pilhaVazia(p)){ //enquanto a pilha tiver algum elemento
		vertice = popPilha(&p); //retira esse elemento
		if(!visitados[vertice]){ //olha se ele ja foi visitado, caso nao tenha sido:
			visitados[vertice]++; //marca como visitado
			printf(" %d", vertice); //imprime o vertice
			No* noh = g.lista[vertice]; //busca a sua lista de vertices adjacentes
			while(noh->prox){ //percorre a lista inserindo todos os elementos da mesma na pilha
				noh = noh->prox;
				pushPilha(&p, noh->vert);
			}
		}
		//repete o procedimento efetuando uma busca em profundidade
	}
	printf("\n");
	return;
}