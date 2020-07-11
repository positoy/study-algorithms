#include <stdio.h>

int stack[100];
int top = -1;
void push(int data) { stack[++top] = data; }
void pop() { --top; }
	
int main()
{
	char buf[100];
	char pbuf[200] = { 0 };
	scanf("%s", buf);

	int pos;
	for (pos=0; buf[pos] != '\0'; pos++)
	{
		switch (buf[pos])
		{
			case '(':
				push(pos);
				break;

			case ')':
				sprintf(pbuf, "%s%d %d\n", pbuf, stack[top], pos);
				pop();
				break;
		}
	}

	if (-1 == top) 
		puts(pbuf);
	else
		puts("not match");
}
