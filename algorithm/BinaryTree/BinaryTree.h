/**
 * TREE : MINIMAL OPERATION SET
 * 
 * create(data)
 * find(data, node) ; will be used by insertNode
 *
 * insert(node, parent) ; as a child
 * 
 * visit(node)
 * traverse(node, [depth])
 * 
 * delete는 작성하지 않아도 좋다. 왜냐하면,
 * 1. 삭제하려는 node의 parent를 알아야하기 때문에 까다롭다.
 * 2. child와 sibling이 존재할 때 삭제 후 어느 것을 어떻게 연결해야 할 지 모호하다.
 * 
 */
 
/**
 * File Name : BinaryTree.c
 * 
 * File Description :
 * Declarations for Binary Tree data structure.
 * 
 * Author  		: positoy (positoy@gmail.com)
 * Dept   		: study
 * Created Data : 2015/03/18
 * Version 		: 0
 * 
 *
 */

#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

#include <stdio.h>
#include <stdlib.h>

typedef char data;

typedef struct _bnode {
	data value;
	struct _bnode *left, *right;
} BNode;

BNode *createNode(data value);
BNode *findNode(data value, BNode *node);

BNode *insertNode(BNode *node, BNode *parent);

void visitNode(BNode *node);
void traverseTree(BNode *node);

void traversePreorder(BNode *node);
void traverseInorder(BNode *node);
void traversePostorder(BNode *node);

void destroyTree(BNode *node);
// destory uses " postorder traversal"

#endif