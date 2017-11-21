#ifndef _GRAFO_H_
#define _GRAFO_H_

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct noh{
	int vert;
	struct noh *prox;
}No;

typedef struct grafo{
	No** lista;
}Grafo;

Grafo criaGrafo(int n);
void insereAresta(Grafo *g, int v, int u);
void buscaLargura(Grafo g, int s);
void buscaProfundidade(Grafo g, int s);

#endif
