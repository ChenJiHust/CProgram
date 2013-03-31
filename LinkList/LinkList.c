#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

//创建链表，头插法
LinkList* createListF(ElemType a[],int n)
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
LinkList * createListR(ElemType a[],int n)
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
LinkList* reverseList(LinkList * l)
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

//链表环判断
int hasCircle(LinkList *l)
{
	LinkList *fast = l,*slow = l;
	while(fast)
	{
		fast = fast->next;
		if(fast)
		{
			if(fast == slow)
			{
				return 1;
			}
			else
			{
				fast = fast->next;
				slow = slow->next;
			}
		}
	}
	return 0;
}


//求环的长度。使用两个指针，快指针比慢指针速度快一赔。从首次相遇到第二次相遇的步数即环长
int calCircleLengh(LinkList *l)
{
	LinkList *fast = l,*slow = l;
	int count = 0;
	while(fast)
	{
		fast = fast->next;
		if(fast)
		{
			if(fast == slow)
			{
				if(count == 0)
					count ++;
				else
					return count;
			}
			else
			{
				fast = fast->next;
				slow = slow->next;
				if(count)
					count ++;
			}
		}
	}
	return 0;

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
	l = createListF(a,8);
	print(l);


//	s = l;
//	while(s->next)
//		s = s->next;
//	s->next = l->next;
	printf("%d\n",calCircleLengh(l));


//	print(l);
//	l = reverseList(l);
//	print(l);
	return 0;
}