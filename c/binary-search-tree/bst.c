#include "bst.h"

No* new_node(int d){
	No* noh = (No*)malloc(sizeof(No));
	noh->right = NULL;
	noh->left = NULL;
	noh->data = d;
	return noh;
}

void free_tree(Tree t){
	if(t){
		No* right = t->right;
		No* left = t->left;
		free(t);
		free_tree(t->right);
		free_tree(t->left);
	}
}

No* search(Tree a, int t){
	if(!a) return NULL;
	if(a->data == t) return a;
	if(a->data > t) return search(a->left, t);
	return search(a->right, t);
}

void insert(Tree *a, int data){
	if(!(*a)){
		(*a) = new_node(data);
		return;
	}
	if(data > (*a)->data){
		insert(&((*a)->right), data);
		return;
	}
	insert(&((*a)->left), data);
}

void pre_ordem(Tree a){
	if(a){
		printf(" %d", a->data);
		pre_ordem(a->left);
		pre_ordem(a->right);
	} 
}

void in_ordem(Tree a){
	if(a){
		in_ordem(a->left);
		printf(" %d", a->data);
		in_ordem(a->right);
	} 
}

void pos_ordem(Tree a){
	if(a){
		pos_ordem(a->left);
		pos_ordem(a->right);
		printf(" %d", a->data);
	} 
}