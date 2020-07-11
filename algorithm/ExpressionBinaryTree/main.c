#include "BinaryTree.h"

char postExpression[100] = { 0 };
static int len, pos;

BNode *makeOperand()
{
	if (--pos < 0)
		return NULL;

	switch (postExpression[pos])
	{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
			return createNode(postExpression[pos]);

		case '+':
		case '-':
		case '*':
		case '/':
			parent = createNode(postExpression[pos]);
			insertNode(makeOperand(), parent);
			insertNode(makeOperand(), parent);
			return parent;

		default:
			return NULL;
	}
}

int main()
{
	BNode *root;

	scanf("%s", postExpression);
	for (len=0; postExpression[len]!='\0'; len++);

	root = makeOperand();

	traverseTree(root);
	destroyTree(root);
}
