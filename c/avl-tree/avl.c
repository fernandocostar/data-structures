#include "avl.h"

/* Cria um novo no com chave k */
No *NovoNo(int k) {
	No *p = malloc(sizeof(No));
	p->esq = p->dir = NULL;
	p->chave = k;
	p->bal = 0;
	return p;
}

/* Libera todos os nos arvore AVL */
void LiberaArvore(Arvore r) {
	if (r != NULL) {
		No *esq = r->esq;
		No *dir = r->dir;
		free(r);
		LiberaArvore(esq);
		LiberaArvore(dir);
	}
	return;
}

/* Funcaos auxiliar para imprimir uma arvore AVL */
void ImprimeChave(int k, int b) {
	int i;
	for (i=0; i<b-1; i++)
		printf("|\t");
	if (b > 0) printf("|-------%d\n",k);
	else printf("%d\n",k);
	return;
}

/* Imprime a arvore */
void ImprimeArvore(Arvore r, int b) {
	if (r == NULL)
		return;
	ImprimeArvore(r->dir, b+1);
	ImprimeChave(r->chave, b);
	ImprimeArvore(r->esq, b+1);
	return;
}

/* Retorna a altura total da arvore */
int Altura(Arvore r) {
/*** COMPLETE AQUI ***/
	int tesq, tdir; //variaveis para o tamanho da subarvore esquerda e direita, respectivamente
	if(!r){ //se for NULL retorna -1
		return -1;
	}
	tdir = Altura(r->dir)+1 //chama recursivamente a altura da subarvore da direita
	tesq = Altura(r->esq)+1 //chama recursivamente a altura da subarvore da esquerda
	if(tdir > tesq){ //retorna tamanho da direita caso seja maior
		return tdir;
	}
	return tesq; //retorna tamanho da esquerda caso seja maior
}


/* Rotacao a direita */
void RD(Arvore *r) {
	No *p = *r;
	No *q = p->esq;
	p->esq = q->dir;
	q->dir = p;
	*r = q;
	return;
}

/* Rotacao a esquerda */
void RE(Arvore *r) {
/*** COMPLETE AQUI ***/
	No* p = *r;
	No* q = p->dir;
	p->dir = q->esq;
	q->esq = p;
	*r = q;
	return;
}

/* Rotacao Dupla EsqDir */
void RED(Arvore *r) {
	No *p = *r;
	No *q = p->esq;
	No *t = q->dir;
	p->esq = t->dir;
	q->dir = t->esq;
	t->esq = q;
	t->dir = p;
	*r = t;
	return;
}

/* Rotacao Dupla DirEsq */
void RDE(Arvore *r) {
/*** COMPLETE AQUI ***/
	No* p = *r;
	No* q = p->dir;
	No* t = q->esq;
	q->esq = t->dir;
	t->dir = q;
	p->dir = t;
	RD(r);
	return;
}

/* Funcao auxiliar de insercao */
int InsereAux(Arvore *r, int k, int *cresceu) {
	if (*r == NULL) {
		*r = NovoNo(k);
		*cresceu = 1;
		return 1;
	}
	if ((*r)->chave == k)
		return 0;
	if (k < (*r)->chave) {
		if (InsereAux(&(*r)->esq, k, cresceu)) {
			if (*cresceu) {
				switch ((*r)->bal) {
					case +1:
						(*r)->bal = 0;
						*cresceu = 0;
					break;
					case 0:
						(*r)->bal = -1;
					break;
					case -1:
						if ((*r)->esq->bal == -1) {
							RD(r);
							(*r)->dir->bal = 0;
						}
						else { 
							RED(r);
							No *e = (*r)->esq, *d = (*r)->dir;
							switch ((*r)->bal) {
								case +1:
									e->bal = -1;
									d->bal = 0;
								break;
								case 0:
									e->bal = 0;
									d->bal = 0;
								break;
								case -1:
									e->bal = 0;
									d->bal = 1;
								break;
							}
						}
						(*r)->bal = 0;
						*cresceu = 0;
					break;
				}
			}
			return 1;
		}
		else 
			return 0;
	}
	if (k > (*r)->chave) {
/*** COMPLETE AQUI ***/
	}
}

/* Insere um noh em uma arvore */
int InsereArvore(Arvore *r, int k) {
	int cresceu;
	return InsereAux(r, k, &cresceu);
}