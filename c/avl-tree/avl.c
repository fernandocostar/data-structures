#include "avl.h"

/*
BALANCEAMENTO UTILIZADO = HD - HE
*/

/* Cria um novo no com chave k */
No *NovoNo(int k) {
	No *p = malloc(sizeof(No)); //aloca espaco para um novo noh
	p->esq = p->dir = NULL; //faz o novo noh ter os dois filhos iguais a NULL
	p->chave = k; //atribui o valor da chave
	p->bal = 0; //como os dois filhos (subarvores) sao NULL entao balanceamento sera 0
	return p; //retorna ponteiro para o noh
}

/* Libera todos os nos arvore AVL */
void LiberaArvore(Arvore r) {
	if (r != NULL) {
		No *esq = r->esq; //variavel auxiliar para o no da esquerda e nao se perder
		No *dir = r->dir; //variavel auxiliar para o no da direita e nao se perder
		free(r); //libera o no recebido atual
		LiberaArvore(esq); //chama recursivamente para os dois filhos
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

/* Retorna a altura total da arvore dada */
int Altura(Arvore r) {
	int tesq, tdir; //variaveis para o tamanho da subarvore esquerda e direita, respectivamente
	if(!r){ //se for NULL retorna -1
		return -1;
	}
	tdir = Altura(r->dir)+1; //chama recursivamente a altura da subarvore da direita
	tesq = Altura(r->esq)+1; //chama recursivamente a altura da subarvore da esquerda
	if(tdir > tesq){ //retorna tamanho da direita caso seja maior
		return tdir;
	}
	return tesq; //retorna tamanho da esquerda caso seja maior
}


/* Rotacao a direita */
void RD(Arvore *r) {
	No *p = *r; //guarda o endereco da raiz da arvore
	No *q = p->esq; //guarda o endereco do noh a esquerda da raiz
	p->esq = q->dir; //seja q->dir maior que a nossa nova raiz porem menor que o noh a direita da nova raiz(antiga raiz) fazemos a direita de q a esquerda de p
	q->dir = p; //a antiga raiz passa a ser o noh direito do antigo noh intermediario
	*r = q; //a nova raiz sera o noh intermediario
	return;
}

/* Rotacao a esquerda */
void RE(Arvore *r) {
	No* p = *r; //guarda o endereco da raiz da arvore
	No* q = p->dir; //guarda o endereco do noh a direita da raiz
	p->dir = q->esq; //seja q->esq maior que a nossa antiga raiz porem menor que o noh a direita da mesma fazemos a esquerda de q a direita de p
	q->esq = p; //a antiga raiz passa a ser o noh esquerdo do antigo noh intermediario
	*r = q; //a nova raiz sera o noh intermediario
	return;
}

/* Rotacao Dupla EsqDir */
void RED(Arvore *r) {
	No *p = *r; //guarda o endereco do no raiz da arvore, chamaremos de noh raiz
	No *q = p->esq; //guarda o endereco do no esquerdo do no raiz, chamaremos de noh intermediario
	No *t = q->dir; //guarda o endereco do no direito do no intermediario, chamaremos de noh final
	p->esq = t->dir; //faz com que a esquerda do noh raiz aponte para a direita do noh final 
	q->dir = t->esq; //faz com que a direita do noh intermediario aponte para a esquerda do noh final
	t->esq = q; //esquerda do noh final passa a ser o noh intermediario
	t->dir = p; //direita do noh final passa a ser o noh raiz
	*r = t; //arvore aponta para o noh final o tranformando em noh raiz
	return;
}

/* Rotacao Dupla DirEsq */
void RDE(Arvore *r) {
	No* p = *r; //guarda o endereco do no raiz da arvore, chamaremos de noh raiz
	No* q = p->dir; //guarda o endereco do no direito do no raiz, chamaremos de noh intermediario
	No* t = q->esq; //guarda o endereco do no direito do no intermediario, chamaremos de noh final
	q->esq = t->dir; //faz com que a esquerda do noh intermediario aponte para a direita do noh final
	p->dir = t->esq; //faz com que a direita do noh raiz aponte para a esquerda do noh final
	t->dir = q; //direita do noh final passa a ser o noh intermediario
	t->esq = p; //esquerda do noh final passa a ser o noh raiz
	*r = t; //arvore aponta para o noh final o tranformando em noh raiz
	return;
}

/* Funcao auxiliar de insercao */
int InsereAux(Arvore *r, int k, int *cresceu) {
	if (*r == NULL) { //se a arvore estiver vazia
		*r = NovoNo(k); //criamos um novo
		*cresceu = 1; //declaramos que a arvore cresceu
		return 1; //retornamos sucesso
	}
	if ((*r)->chave == k) //se a chave do noh que estamos olhando for igual ao que queremos adicionar nao fazemos nada
		return 0;
	if (k < (*r)->chave) { //se o noh que queremos adicionar for menor que o noh atual
		if (InsereAux(&(*r)->esq, k, cresceu)) { //chamamos a funcao de insercao
			if (*cresceu) { //se a arvore cresceu
				switch ((*r)->bal) { //olhamos o antigo balanceamento
					case +1: //se o lado direito era maior e adicionamos no lado esquerdo
						(*r)->bal = 0; //agora ambos os lados tem mesmo tamanhos, balanceamento igual a 0
						*cresceu = 0; //a arvore na modificou sua altura
					break; 
					case 0: //se ambos os lados da arvore eram iguais
						(*r)->bal = -1; //agora o lado esquerdo sera maior, balanceamento igual a -1
					break;
					case -1: //se o lado esquerdo era maior e adicionamos mais um noh no mesmo
						if ((*r)->esq->bal == -1) { //se a subarvore da esquerda tem seu lado esquerdo maior
							RD(r); //temos o caso trivial de uma rotacao simples a direita
							(*r)->dir->bal = 0; //balanceamos a subarvore direita apos a rotacao
						}
						else { //senao, entao temos o caso onde adicionamos o noh no filho direito da subarvore da esquerda
							RED(r); //necessitando uma rotacao dupla a direita
							No *e = (*r)->esq, *d = (*r)->dir; //variaveis auxiliares para as subarvores da esquerda e direita
							switch ((*r)->bal) { //dependendo da disposicao da arvore principal rebalanceamos as arvores intermediarias
								case +1: //caso o lado direito seja maior
									e->bal = -1;
									d->bal = 0;
								break;
								case 0: //caso ambos os lados tenham o mesmo tamanho
									e->bal = 0;
									d->bal = 0;
								break;
								case -1: //caso o lado esquerdo seja maior
									e->bal = 0;
									d->bal = 1;
								break;
							}
						}
						(*r)->bal = 0; //caso chegue aqui significa que ambos os lados tem mesmo tamanho na arvore principal
						*cresceu = 0; //e que ela nao cresceu
					break;
				}
			}
			return 1;
		}
		else 
			return 0;
	}
	if (k > (*r)->chave) { //se o noh que queremos adicionar for maior que o noh atual
		if(InsereAux(&(*r)->dir, k, cresceu)){ //chamamos a funcao de insercao
			if(*cresceu){ //se a arvore cresceu
				switch ((*r)->bal){ //olhamos o antigo balanceamento
					case -1: //se o lado esquerdo era maior e adicionamos no lado direito
						(*r)->bal = 0;
						*cresceu = 0;
						break;
					case 0: //se ambos os lados da arvore eram iguais
						(*r)->bal = 1; //agora o lado direito sera maior, balanceamento igual a 1
						break;
					case +1: //se o lado direito era maior e adicionamos mais um noh no mesmo
						if((*r)->dir->bal == 1){ //se a subarvore da direita tem seu lado direito maior
							RE(r); //temos o caso trivial de uma rotacao simples a esquerda
							(*r)->esq->bal = 0; //balanceamos a subarvore esquerda apos a rotacao
						}else{ //senao, entao temos o caso onde adicionamos o noh no filho esquerdo da subarvore da direita
							RDE(r); //necessitando uma rotacao dupla a esquerda
							No* e = (*r)->esq; //variaveis auxiliares
							No* d = (*r)->dir; //contendo o endereco das subarvores da direita e esquerda
							switch ((*r)->bal){ //dependendo da disposicao da arvore principal rebalanceamos as arvores intermediarias
								case -1: //caso o lado esquerdo seja maior
									e->bal = 0;
									d->bal = 1;
									break;
								case 0: //caso ambos os lados tenham mesmo tamanho
								e->bal = 0;
								d->bal = 0;
								break;
								case 1: //caso o lado direito seja maior
									d->bal = 0;
									e->bal = -1;
								break;
							}
						}
					(*r)->bal = 0; //caso chegue aqui significa que ambos os lados tem mesmo tamanho na arvore principal
					*cresceu = 0; //e que ela nao cresceu
					break;
				}
			}
			return 1;
		}
		else
			return 0;
	}
}

/* Insere um noh em uma arvore */
int InsereArvore(Arvore *r, int k) {
	int cresceu; //variavel auxiliar para saber se ao adicionar um noh a mesma aumenta sua altura
	return InsereAux(r, k, &cresceu);
}