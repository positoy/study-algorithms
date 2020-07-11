/**
 * Project Name : Left Child - Right Sibling Tree
 * 
 * Copyright : 2015 by positoy
 * 
 * Project Description :
 * Definitions and declarations for LCRS Tree data structure.
 * 
 */

/**
 * File Name : LCRSTree.c
 * 
 * File Description :
 * Definitions for LCRS Tree data structure.
 * 
 * Author  		: positoy (positoy@gmail.com)
 * Dept   		: study
 * LCRS_createNoded Data : 2015/03/17
 * Version 		: 0
 * 
 */

#include "LCRSTree.h"

LCRSNode *LCRS_createNode(data value)
{
	LCRSNode *newNode = (LCRSNode*)malloc(sizeof(LCRSNode*));

	newNode->value = value;
	newNode->LeftChild = NULL;
	newNode->RightSibling = NULL;

	return newNode;
}

LCRSNode *LCRS_findNode(data value, LCRSNode *node)
{
	LCRSNode *returnLeft, *returnRight;

	if (node == NULL)
		return NULL;

	if (node->value == value)
	{
		return node;
	}
	else
	{
		returnLeft = LCRS_findNode(value, node->LeftChild);
		if (returnLeft != NULL)
			return returnLeft;

		returnRight = LCRS_findNode(value, node->RightSibling);
		return returnRight;
	}
}

LCRSNode *LCRS_insertChild(data value, LCRSNode *parent)
{
	LCRSNode *newNode = LCRS_createNode(value);
	newNode->LeftChild = newNode->RightSibling = NULL;

	if (parent->LeftChild == NULL)
	{
		parent->LeftChild = newNode;
	}
	else
	{
		LCRSNode *node = parent->LeftChild;

		while (node->RightSibling)
		{
			node = node->RightSibling;
		}

		node->RightSibling = newNode;
	}

	return newNode;
}

LCRSNode *LCRS_insertSibling(data value, LCRSNode *currentNode)
{
	LCRSNode *newNode = LCRS_createNode(value);
	newNode->LeftChild = NULL;
	newNode->RightSibling = currentNode->RightSibling;

	currentNode->RightSibling = newNode;

	return newNode;
}

data LCRS_visit(LCRSNode *node)
{
	if (node == NULL)
		return -1;

	printf("visit : %d\n", node->value);
	return node->value;
}

void LCRS_traverse(LCRSNode *node)
{
	if (node == NULL)
		return;

	LCRS_visit(node);

	if (node->LeftChild != NULL)
		LCRS_traverse(node->LeftChild);

	if (node->RightSibling != NULL)
		LCRS_traverse(node->RightSibling);
}

void LCRS_printTree(LCRSNode *node, int depth)
{
	if (node == NULL)
		return;

	int i;
	for (i=0; i<depth; i++)
		printf("    ");
	printf("%d\n", node->value);

	if (node->LeftChild != NULL)
		LCRS_printTree(node->LeftChild, depth+1);

	if (node->RightSibling != NULL)
		LCRS_printTree(node->RightSibling, depth);
}
