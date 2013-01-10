#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "BST.h"


BST insert(BST tree,int data)
{
	if(tree == NULL)
	{
		tree = malloc(sizeof(struct node));
		if(tree !=NULL)
		{
			tree->data = data;
			tree->lchild=tree->rchild = NULL;
		}
	}
	else if(data < tree->data)
		tree->lchild = insert(tree->lchild,data);
	else if(data>tree->data)
		tree->rchild = insert(tree->rchild,data);
	return tree;
}

BST search(const BST node,int data)
{
	if(node == NULL)
		return NULL;
	if(node->data == data)
		return node;
	else if(node->data < data)
		return search(node->rchild,data);
	else
		return search(node->lchild,data);
}
