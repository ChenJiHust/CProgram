#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

//创建链表，头插法
LinkList* CreateListF(ElemType a[],int n)
{
	LinkList *s,*l = NULL;
	int i;
	for(i = 0;i<n;i++)
	{
		s = (LinkList*)malloc(sizeof(LinkList));
		s->next = l;
		s->data = a[i];
		l = s;
	}
	return l;
}

//创建链表尾插法
LinkList * CreateListR(ElemType a[],int n)
{
	LinkList *l=NULL,*head=NULL,*tail=NULL;
	int i = 0;
	for(i=0;i<n;i++)
	{
		l = (LinkList*)malloc(sizeof(LinkList));
		l->next = NULL;
		l->data = a[i];
		if(i==0)
		{
			head = tail = l;
		}
		else{
			tail->next = l;
			tail=l;
		}
	}
	return head;
}


//链表逆序，反转链表。类似头插法
LinkList* ReverseList(LinkList * l)
{
	LinkList *s = NULL,*head;
	while(l!=NULL)
	{
		head = l;
		l = l->next;
		head->next = s;
		s = head;
	}
	return s;
}

void print(LinkList * l)
{
	while(l!=NULL)
	{
		printf("%d\t",l->data);
		l = l->next;
	}
	printf("\n");
}

int main()
{
	LinkList *l = NULL,*s;
	int a[8] = {5,2,6,9,0,1,4,3};
	l = CreateListF(a,8);
	print(l);
	l = ReverseList(l);
	print(l);
	return 0;
}