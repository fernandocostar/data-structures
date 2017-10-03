#ifndef LISTA_H_
#define LISTA_H_

#include <stdlib.h>
#include <stdio.h>

typedef struct no{
	int data;
	struct no* next;
}No;

typedef No* List;

List create();
void free_list(List* l);
void insert(List* l, int d, int i);
void insert_right(List* l, int d);
void insert_left(List* l, int d);
void remove(List* l, int i);
int size(List l);
int isEmpty(List l);
void sort(List* l);

#endif