#include <stdio.h>
#include "LCRSTree.h"

int main()
{
	LCRSNode *root = LCRS_createNode(0);

	LCRS_insertChild(1, root);
	LCRS_insertChild(2, root);
	LCRS_insertChild(3, root);

	LCRS_insertChild(21, LCRS_findNode(2, root));
	LCRS_insertChild(22, LCRS_findNode(2, root));
	LCRS_insertChild(24, LCRS_findNode(2, root));

	LCRS_insertSibling(23, LCRS_findNode(22, root));

	LCRS_insertChild(231, LCRS_findNode(23, root));
	
	puts("\n//traverse");
	LCRS_traverse(root);

	puts("\n//printTree");
	LCRS_printTree(root, 0);
}
