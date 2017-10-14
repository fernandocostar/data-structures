#include "list.h"
//creates a list//
List create(){
	List l = NULL; //To create an empty list we create a pointer to a NULL node
	return l;
}

//destroys the list//
void free_list(List* l){
	No* n = *l; //copy the node that the list points to
	while(n != NULL){
		No* aux = n;
		n = n->next;
		free(aux);
	}
	return;
}

//insert a data in an specific index in a list//
void insert(List* l, int d, int i){
	No* new_node = (No*)malloc(sizeof(No)); //create a new node
	new_node->data = d; //store the data

	No* n = *l; //copy the first element adress
	int count = 0;

	if(!(*l)){
		printf("Empty.\n");
	}

	if(i == 0){
		insert_left(l, d);
		return;
	}

	if(i == size((*l))){
		insert_right(l, d);
		return;
	}

	if(i > 0 && i < size((*l))){
		while(count < (i-1)){
			n = n->prox;
		}
		No* aux = n->prox;
		n->prox = new_node;
		new_node->prox = aux;
		return;
	}
	exit(-1);
}

//inserts a data on the left of the list//
void insert_left(List* l, int d){
	No* new_node = (No*)malloc(sizeof(No));
	new_node->data = d;
	new_node->prox = NULL;

	if(!(*l)){
		(*l) = new_node;
		return;
	}

	No* first = (*l);
	(*l) = new_node;
	new_node->prox = first;
	return;
}

//inserts a data on the rigth of the list//
void insert_right(List* l, int d){
	No* new_node = (No*)malloc(sizeof(No));
	new_node->data = d;
	new_node->prox = NULL;

	if(!(*l)){
		(*l) = new_node;
		return;
	}

	No* aux = (*l);
	while(aux->prox){
		aux = aux->prox;
	}
	aux->prox = new_node;
	return;
}

//removes and returns the data at an index//
int remove(List* l, int i){
	int data, counter = 0;
	No* aux = (*l);

	if(!aux){
		exit(-1);
	}

	if(!(aux->prox) && i == 0){
		remove_left(l);
		return;
	}

	while(counter != (i-1)){
		aux = aux->prox;
	}

	data = aux->prox->data;

	if(aux->prox->prox){
		No* prox = aux->prox->prox;

		free(aux->prox);
		aux->prox = prox;
		return data;
	}

	free(aux->prox);
	aux->prox = NULL;
	return data;
}

//removes and returns the data at the start of the list//
int remove_left(List* l){
	int data;
	No* aux = (*l);

	if(!aux){
		exit(-1);
	}

	data = aux->data;

	if(!(aux->prox)){
		(*l) = NULL;
		free(aux);
		return data;
	}

	No* prox = aux->prox;
	free(aux);
	(l*) = prox;
	return data;
}

//removes and returns the data on the list right side//
int remove_rigth(List* l){
	int data;
	if(!(*l)){
		exit(-1);
	}
	
	No* aux = (*l);

	if(!aux->prox){
		data = aux->data;
		(*l) = NULL;
		free(aux);
		return data;
	}

	while(aux->prox->prox){
		aux = aux->prox;
	}
	data = aux->prox->data;
	free(aux->prox);
	aux->prox = NULL;
	return data;
}

//returns the size of the list//
int size(List l){
	No* aux = l;
	int count;

	if(isEmpty(l)) return -1;

	while(aux->prox){
		aux = aux->prox;
		count++;
	}

	return count;
}

//returns if the list is empty//
int isEmpty(List l){
	return l == NULL;
}

//prints the full list//
void print_list(List l){
	if(!l){
		printf("Empty.\n");
	}
	No* aux = l;
	while(aux){
		print(aux->data);
	}
	printf("\n");
	return;
}