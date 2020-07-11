#include <stdio.h>
#include <string.h>

/* FORWARD STACK */
char forward_stack[200][80];
int forward_top;

char* forward_pop() {
	if (forward_top == -1) return NULL;
	else return forward_stack[forward_top--];
}

char* forward_push(char* s) {
//	if (strcmp(s, "Ignored") != 0)
		strcpy(forward_stack[++forward_top], s);
}

/* BACKWARD STACK */
char backward_stack[200][80];
int backward_top;

char* backward_pop() {
	if (backward_top == -1) return NULL;
	else return backward_stack[backward_top--];
}

char* backward_push(char* s) {
		strcpy(backward_stack[++backward_top], s);
}

char* getUrl(char* s) {
	int i;
	for (i=0; i<80; i++)
	{
		if (s[i] == 'h')
		{
			return s + i;
		}
	}
}

int main()
{
	int T, t;
	scanf("%d", &T);

	for (t=1; t<=T; t++)
	{
		char cmd[10];
		char url[80];
		char current[80];
		int ignored;
		char* pop;

		// ÃÊ±âÈ­
		forward_top = backward_top = -1;
		strcpy(current, "https://secmem.org/");
		
		printf("#testcase%d\n", t);
		while (1)
		{
			// input
			scanf("%s", cmd);
			if (cmd[0] == 'V')
			{
				scanf("%s", url);
			}
			ignored = 0;

			// process
			switch (cmd[0])
			{
			case 'B':
				pop = backward_pop();
				if (pop == NULL)
				{
					ignored = 1;
				}
				else
				{
					forward_push(current);
					strcpy(current, pop);
				}
				break;

			case 'F':
				pop = forward_pop();
				if (pop == NULL)
				{
					ignored = 1;
				}
				else
				{
					backward_push(current);
					strcpy(current, pop);
				}
				break;

			case 'V':
				backward_push(current);
				strcpy(current, url);
				forward_top = -1;
				break;
			}
			
			// output
			if (cmd[0] == 'Q')
			{
				break;
			}
			else
			{
				if(ignored)
				{
					printf("Ignored\n");
				}
				else
				{
					printf("%s\n", current);
				}
			}

		}
	}
}
