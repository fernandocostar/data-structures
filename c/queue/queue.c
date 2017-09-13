#include "queue.h"
#include <stdlib.h>

Queue create(){
	Queue q;
	q.start = -1;
	q.end = 0;
}

void push(int element, Queue* q){
	if((*q).start == -1){
		(*q).start++;
		(*q).elements[0] = element;
		(*q).end++;
		return;
	}if((*q).start == 0 && (*q).end == 100){
		printf("Your Queue is full.\n");
		exit(-1);
	}else if((*q).end <= 99){
		int i;
		for(i = (*q).start; i <= (*q).end; i++){
            (*q).elements[i -(*q).start] = (*q).elements[i];
		}
		(*q).elements[(*q).end] = element;
		(*q).end++;
		return;
	}
	(*q).elements[(*q).end] = element;
	(*q).end++;
	return;
}

int pop(Queue* q){
	int r;
	if((*q).start == -1){
		printf("Your Queue is empty.\n");
		exit(-1);
	}else if((*q).start == (*q).end){
		r = (*q).elements[(*q).start];
		(*q).start = -1;
		(*q).end = 0;
		return r;
	}
	r = (*q).elements[(*q).start];
	(*q).start++;
	return r;
}

void print_queue(Queue* q){
	int i, start = (*q).start, end = (*q).end;
	for(i = start; i < end; i++){
		printf("%d, ", (*q).elements[i]);
	}
	printf("\n");
}

int isFull(Queue q) {
	return q.start == 0 && q.end == 100;
}

int isEmpty(Queue q) {
	return q.start == -1;
}

int size(Queue q) {
	return (q.end-q.start)+1;
}