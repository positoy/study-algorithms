#include <stdio.h>
#define isFull() (top == 99)
#define isEmpty() (top == -1)

typedef int type;

type stack[100];
int top = -1;

void push(type data) { stack[++top] = data; }
void pop() { top--; }

// type pop() { stack[top--]; }

// 이렇게 쓰면 pop으로 데이터를 리턴 받을 수 있다.
// 하지만 STL에서는 pop 동작이 단순히 스택의 최상위 데이터를 버리는데 사용된다.
// 따라서 stack[top] 으로 데이터에 접근하고 이후에 pop()으로 최상위 데이터를 제거해준다.

int main()
{
	int i = 1;

	while (!isFull())
	{
		push(i++);
	}

	while(!isEmpty())
	{
		printf("[%d] ", stack[top]);
		pop();
	}
}
