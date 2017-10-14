#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int data;
	struct no* esq;
	struct no* dir; 
}No;

typedef No* Tree;

No* new_node(int d){
	No* noh = (No*)malloc(sizeof(No));
	noh->dir = NULL;
	noh->esq = NULL;
	noh->data = d;
	return noh;
}

void free_tree(Tree t){
	if(t){
		No* dir = t->dir;
		No* esq = t->esq;
		free(t);
		free_tree(t->dir);
		free_tree(t->esq);
	}
}

void insert(Tree *a, int data){
	if(!(*a)){
		(*a) = new_node(data);
		return;
	}
	if(data > (*a)->data){
		insert(&((*a)->dir), data);
		return;
	}
	insert(&((*a)->esq), data);
}

/*
No* insert(No* a, int data){
	if (!a) return new_node(data);
	if (a->data < data) return insert(a->dir,data);
	return insert(a->esq,data);
}
*/

void pre_ordem(Tree a){
	if(a){
		printf(" %d", a->data);
		pre_ordem(a->esq);
		pre_ordem(a->dir);
	} 
}

void in_ordem(Tree a){
	if(a){
		in_ordem(a->esq);
		printf(" %d", a->data);
		in_ordem(a->dir);
	} 
}

void pos_ordem(Tree a){
	if(a){
		pos_ordem(a->esq);
		pos_ordem(a->dir);
		printf(" %d", a->data);
	} 
}

int main(){
	int i, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		printf("Case %d:\n", i+1);
		int k, j, aux;
		scanf("%d", &k);
		Tree l = NULL;
		for(j = 0; j < k; j++){
			scanf("%d", &aux);
			insert(&l, aux);
		}
		printf("Pre.:");
		pre_ordem(l);
		printf("\n");
		printf("In..:");
		in_ordem(l);
		printf("\n");
		printf("Post:");
		pos_ordem(l);
		printf("\n");
		free_tree(l);
		printf("\n");
	}
	return 0;
}
