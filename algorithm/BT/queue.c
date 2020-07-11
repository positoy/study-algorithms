#include <stdio.h>
#define MAX_Q 100
#define isEmpty() (tail < head)
#define isFull() (tail + 1 == MAX)

typedef int type;

type queue[MAX];
int head = 0, tail = -1;

void enqueue(type data)
{
	if (!isFull())
		queue[++tail] = data;
}

type dequeue()
{
	if (isEmpty())
		return -1;
	else
		return queue[head++];
}


