#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

//��������ͷ�巨
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

//��������β�巨
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


//�������򣬷�ת��������ͷ�巨
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

//�����ж�
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


//�󻷵ĳ��ȡ�ʹ������ָ�룬��ָ�����ָ���ٶȿ�һ�⡣���״��������ڶ��������Ĳ���������
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