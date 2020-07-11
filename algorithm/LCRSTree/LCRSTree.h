/**
 * TREE : MINIMAL OPERATION SET
 * 
 * createNode(data)
 * findNode(data, node) ; will be used by insertNode
 *
 * insertNode(node, parent) ; as a child
 * 
 * visitNode(node)
 * traverseTree(node, [depth])
 * 
 * delete는 작성하지 않아도 좋다. 왜냐하면,
 * 1. 삭제하려는 node의 parent를 알아야하기 때문에 까다롭다.
 * 2. child와 sibling이 존재할 때 삭제 후 어느 것을 어떻게 연결해야 할 지 모호하다.
 * 
 */
 
/**
 * File Name : LCRSTree.c
 * 
 * File Description :
 * Declarations for LCRS tree data structure.
 * 
 * Author  		: positoy (positoy@gmail.com)
 * Dept   		: study
 * Created Data : 2015/03/17
 * Version 		: 0
 * 
 */

#ifndef __LCRSTREE_H__
#define __LCRSTREE_H__

 #include <stdio.h>
 #include <stdlib.h>

typedef int data;

typedef struct lcrsnode {
	data value;
	struct lcrsnode *LeftChild, *RightSibling;
} LCRSNode;

LCRSNode *LCRS_createNode(data value);

LCRSNode *LCRS_find(data value, LCRSNode *node);

LCRSNode *LCRS_insertChild(data value, LCRSNode *node);
LCRSNode *LCRS_insertSibling(data value, LCRSNode *node);

data LCRS_visit(LCRSNode *node);
void LCRS_traverse(LCRSNode *node);
void LCRS_printTree(LCRSNode *node, int depth);

// we don't really want to consider deletion operation in tree structure.

#endif
