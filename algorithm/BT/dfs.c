#include <stdio.h>

int stack[100] = {0};
int top = -1;
void push(int data) { stack[++top] = data; }
int pop()
{
	if (top == -1)
		return -1;
	else
		return stack[top--];
}

void sort(int *candi, int size)
{
	int i,j,biggest;

	// descending order
	for (i=0; i<size; i++)
	{
		biggest = candi[size-1];

		for (j=size-1; j>i; j--)
		{
			if (candi[j] > candi[j-1])
			{
				biggest = candi[j];
				candi[j] = candi[j-1];
				candi[j-1] = biggest;
			}
		}
	}
}

int main()
{
	int vertexNum, start;
	int graph[11][11] = {0};
	int visited[11] = {0};
	int candi[11];

	/**********
	 input
	 **********/
	scanf("%d %d", &vertexNum, &start);

	int i = 1;
	int a, b;
	while (scanf("%d %d", &a, &b))
		graph[a][b] = graph[b][a] = 1;

	push(start);
	visited[start] = 1;

	// pop (until empty)
	int child;
	while ( (a = pop()) != -1 )
	{
		// visit
		printf("%d ", a);

		// check children, ready candidates
		int num = 0;
		for (child=1; child<=vertexNum; child++)
		{
			if(graph[a][child] == 1 && visited[child] == 0)
				candi[num++] = child;
		}

		// sort
		sort(candi, num);

		// push
		for (child=0; child<num; child++)
		{
			push(candi[child]);
			visited[candi[child]] = 1;
		}
	}
}