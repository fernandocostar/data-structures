#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdio.h>
#define MAX 100

typedef struct queue{
	int elements[MAX];
	int start;
	int end;
}Queue;

Queue create();
void push(int element, Queue* q);
int pop(Queue* q);
int size(Queue q);
int isEmpty(Queue q);
int isFull(Queue q);
void print_queue(Queue* q);

#endif