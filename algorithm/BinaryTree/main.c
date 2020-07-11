#include "BinaryTree.h"

int main()
{
	BNode *root = createNode('A');

	insertNode(createNode('B'), root);
	insertNode(createNode('C'), root);

	insertNode(createNode('D'), findNode('B', root));
	insertNode(createNode('E'), findNode('B', root));

	insertNode(createNode('F'), findNode('C', root));

	// printf("%d\n%p\n%p\n", root->value, root->left, root->right);

//	traversePostorder(root);
	traverseTree(root);

	destroyTree(root);

}
