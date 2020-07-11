/**
 * Project Name : Binary Tree
 * 
 * Copyright : 2015 by positoy
 * 
 * Project Description :
 * Definitions and declarations for Binary Tree data structure.
 * 
 */

/**
 * File Name : BinaryTree.c
 * 
 * File Description :
 * Definitions for Binary Tree data structure.
 * 
 * Author  		: positoy (positoy@gmail.com)
 * Dept   		: study
 * LCRS_createNoded Data : 2015/03/17
 * Version 		: 0
 * 
 */

#include "BinaryTree.h"

BNode *createNode(data value)
{
	BNode *newNode = (BNode*)malloc(sizeof(BNode));;

	newNode->value = value;
	newNode->left = newNode->right = NULL;

	return newNode;
}

BNode *findNode(data value, BNode *node)
{
	BNode *returnLeft, *returnRight;

	if (node == NULL)
		return NULL;

	if (value == node->value)
	{
		return node;
	}
	else
	{
		returnLeft = findNode(value, node->left);
		if (returnLeft != NULL)
			return returnLeft;

		returnRight = findNode(value, node->right);
		return returnRight;
	}
}

BNode *insertNode(BNode *node, BNode *parent)
{
	if (parent->left == NULL)
		return (parent->left = node);
	else if (parent->right == NULL)
		return (parent->right = node);
}

void visitNode(BNode *node)
{
	if (node == NULL)
		return;

	printf("visit: %c\n", node->value);
}

void traverseTree(BNode *node)
{
	traversePreorder(node);
}

void traversePreorder(BNode *node)
{
	if (node == NULL)
		return;

	printf("visit: %c\n", node->value);
	traversePreorder(node->left);
	traversePreorder(node->right);
}

void traverseInorder(BNode *node)
{
	if (node == NULL)
		return;

	traverseInorder(node->left);
	printf("visit: %c\n", node->value);
	traverseInorder(node->right);
}

void traversePostorder(BNode *node)
{
	if (node == NULL)
		return;

	traversePostorder(node->left);
	traversePostorder(node->right);
	printf("visit: %c\n", node->value);
}

void destroyTree(BNode *node)
{
	if (node == NULL)
		return NULL;

	destroyTree(node->left);
	destroyTree(node->right);
	free(node);
}
