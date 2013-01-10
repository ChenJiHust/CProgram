#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "BST.h"

int main()
{
	BST T = NULL;
	BST tmp = NULL;
	int i;
	for(i=0;i<3;i++)
		T = insert(T,i);

	tmp = search(T,2);

	if(tmp != NULL)
		printf("%d",tmp->data);
	return 0;
}