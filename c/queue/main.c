#include <stdio.h>
#include "queue.h"

int main(){
	int i;
	Queue q = create();
	//empty
	//i = pop(&q); //program crashes
	push(1, &q);
	print_queue(&q);
	//q = [1]
	push(2, &q);
	print_queue(&q);
	//q = [1, 2]
	push(3, &q);
	print_queue(&q);
	//q = [1, 2, 3]
	i = pop(&q);
	print_queue(&q);
	//i = 1 and q = [2, 3]
	push(4, &q);
	print_queue(&q);
	//q = [2, 3, 4]




	return 0;
}