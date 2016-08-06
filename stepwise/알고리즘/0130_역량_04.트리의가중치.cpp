#include <stdio.h>

typedef struct _cost {
	int target, cost;
} COST;

typedef struct _sizeinfo {
	int now, cap;
} SIZEINFO;

typedef struct _pathinfo {
	int x,y,cost;
} PATHINFO;

typedef struct _stackinfo {
	int parent, target;
} STACKINFO;

typedef struct _costinfo {
	int a,b,cost;
} COSTINFO;

COSTINFO costset[1000];
int costset_size = 0;
long long result = 1;

STACKINFO st[100] = {};
int top = -1;
void push(STACKINFO s)
{
	st[++top] = s;
}
STACKINFO* pop()
{
	if (top != -1)
		return &st[top--];
	else
		return NULL;
}

SIZEINFO info[100000] = {0};
COST *tree[100000] = {0};

char visited[100000] = {};

void visit(int n);
void putIn(COSTINFO c);

// 메모리관리
void addPath(int a, int b, int c)
{
	COST *newA, *newB;
	int i,j;
	
	// 공간이 모자라면 용량 추가
	if(info[a].now + 1 > info[a].cap)
	{
		newA = (COST*)malloc(sizeof(COST) * info[a].cap + 10);
		for (i=0; i<info[a].now; i++)
			newA[i] = tree[a][i];
		
		tree[a] = newA;
		info[a].cap += 10;
	}

	if(info[b].now + 1 > info[b].cap)
	{
		newB = (COST*)malloc(sizeof(COST) * info[b].cap + 10);
		for (i=0; i<info[a].now; i++)
			newB[i] = tree[b][i];
		
		tree[b] = newB;
		info[b].cap += 10;
	}

	// a에 b추가
	tree[a][info[a].now].target = b;
	tree[a][info[a].now].cost = c;
	info[a].now++;

	// b에 a추가
	tree[b][info[b].now].target = a;
	tree[b][info[b].now].cost = c;
	info[b].now++;
}

void visit();

int main()
{
	int  a,b,c;
	while(1)
	{
		scanf("%d %d %d", &a, &b, &c);
		addPath(a,b,c);
	}

	visit(0);
	printf("%d\n", result);

}

void visit(int n)
{
	int i, childsize;
	COSTINFO c;

	visited[n] = 1;
	childsize = info[n].now;
	for (i=0; i<childsize; i++)
	{
		c.a = n;
		c.b = tree[n][i].target;
		c.cost = tree[n][i].cost;
		putIn(c);
		visit(c.b);
	}
}

void putIn(COSTINFO c)
{
	int i,j;
	costset_size;
	COSTINFO connection;

	// costset은 말그대로 set,
	// 배열에서 아이템 제거하면 빵꾸 생기고 사이즈에도 제한이 있으므로 해결해야함.

	for (i=0; i<costset_size; i++)
	{
		// costset[i]와 c를 연결하고 비용을 계산하여 costset에 추가한다.
		if (c.a == costset[i].a)
		{
			connection.a = c.b;
			connection.b = costset[i].b;
			connection.cost = c.cost * costset[i].cost;

			// costset에 connection을 추가한다.
		}
		else if (c.a == costset[i].b)
		{
			connection.a = c.b;
			connection.b = costset[i].a;
			connection.cost = c.cost * costset[i].cost;

			// costset에 connection을 추가한다.
		}
		else if (c.b == costset[i].a)
		{
			connection.a = c.a;
			connection.b = costset[i].b;
			connection.cost = c.cost * costset[i].cost;

			// costset에 connection을 추가한다.
		}
		else if (c.b == costset[i].b)
		{
			connection.a = c.a;
			connection.b = costset[i].a;
			connection.cost = c.cost * costset[i].cost;

			// costset에 connection을 추가한다.
		
		}
		else
		{
			result = (result * costset[i].cost) % 1000000007;

			// costset에서 costset[i]를 제거한다.
		}

		
	}

}
