#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define Max 20         //����������

typedef struct node{
	char data;
	struct node *lchild,*rchild;
}BinTNode;            //�Զ���������Ľ������

typedef BinTNode *BinTree;    //�����������ָ��

int NodeNum,leaf;   //NodeNumΪ�������leafΪҶ����
//������������㷨����������

//Ҫ�������������У����м�������"#"��ʾ��ָ���λ��
BinTree CreatBinTree(char *str){
	BinTree T = NULL,stack[Max],p;
	int top = -1,k,j=0;
	char ch = *str;
	while(ch !='\0')
	{
		switch(ch)
		{
		case '(':
			top++;
			stack[top] = p;
			k = 1;
			break;
		case ')':
			top--;
			break;
		case ',':
			k = 2;
			break;
		default:
			p = (BinTNode *)malloc(sizeof(BinTNode));
			p->data = ch;
			p->lchild = p->rchild = NULL;
			if(T == NULL)
				T = p;
			else
			{
				switch(k)
				{
				case 1:
					stack[top]->lchild = p;
					break;
				case 2:
					stack[top]->rchild = p;
					break;

				}
			}
		}
		j++;
		ch = str[j];
	}
	return T;
}

//�������
void Preorder(BinTree T){
	if(T)
	{
		printf("%c",T->data);    //���ʽ��
		Preorder(T->lchild);    //�������������
		Preorder(T->rchild);    //�������������
	}
}


//�ǵݹ��������
void Preorder1(BinTree T)
{
	BinTree stack[Max];
	BinTree tmp;
	int top = -1;
	if(T)
	{
		top++;
		stack[top] = T;
		while(top>-1)
		{
			tmp = stack[top];
			top--;
			printf("%c",tmp->data);
			if(tmp->rchild != NULL)
			{
				top++;
				stack[top] = tmp->rchild;
			}
			if(tmp->lchild != NULL)
			{
				top++;
				stack[top] = tmp->lchild;
			}
		}
	}

}
//�������
void Inorder(BinTree T){
	if(T)
	{
		Inorder(T->lchild);      //�������������
		printf("%c",T->data);    //���ʽ��
		Inorder(T->rchild);      //�������������
	}
}

//��������ǵݹ�
void Inorder1(BinTree T)
{
	BinTree stack[Max];
	int top = -1;
	if(T)
	{
		while(top>-1 || T)
		{
			while(T)
			{
				top ++;
				stack[top] = T;
				T = T->lchild;
			}
			if(top != -1)
			{
				T = stack[top];
				top--;
				printf("%c",T->data);
				T = T->rchild;
			}
		}
	}
}

void MorrisInorder(BinTree T)
{
	BinTree pre = NULL;
	while(T)
	{
		if(!T->lchild)
		{
			printf("%c",T->data);
			T = T->rchild;
		}
		else
		{
			pre = T->lchild;
			while(pre->rchild != NULL && pre->rchild != T)
				pre = pre->rchild;
			if(!pre->rchild)
			{
				pre->rchild = T;
				T = T->lchild;
			}
			else
			{
				pre->rchild = NULL;
				printf("%c",T->data);
				T = T->rchild;
			}
		}
	}

}

//�������
void Postorder(BinTree T){
	if(T)
	{
		Postorder(T->lchild);    //�������������
		Postorder(T->rchild);    //�������������
		printf("%c",T->data);    //���ʽ��
	}
}
//��������ǵݹ�
void Postorder1(BinTree T)
{
	BinTree stack[Max],p;
	int top = -1;
	int flag;
	if(T)
	{
		do{
			while(T)
			{
				top++;
				stack[top] = T;
				T = T->lchild;
			}
			flag = 1;
			p = NULL;                  //�ոշ��ʹ��Ľ�㡣
			while(top != -1 && flag)
			{
				T = stack[top];				
				if(T->rchild == p)
				{
					printf("%c",T->data);
					top--;
					p = T;
				}
				else
				{
					flag = 0;
					T = T->rchild;
				}
			}
		}while(top>-1);
	}
}



//���ú�����������������ȡ��������Ҷ�����ĵݹ��㷨
int TreeDepth(BinTree T){
	int hl,hr,max;
	if(T)
	{
		hl=TreeDepth(T->lchild);   	//�������
		hr=TreeDepth(T->rchild);    //�������
		max=hl>hr? hl:hr;           //ȡ������ȵ����ֵ
		NodeNum=NodeNum+1;         //������
		if(hl==0&&hr==0) 
			leaf=leaf+1;           //���������Ϊ0����ΪҶ�ӡ�
		return(max+1);
	}
	else
		return(0);
}
/*
//�������
Levelorder( BinTNode *root){
	BinTNode * q[Max];          //����BinTNode���͵Ķ��� ���ڴ�Žڵ� ���г����Ϊ20��Ԫ��
	int front=0,rear=0;                  //��ʼ������Ϊ��
	BinTNode *p;                          //��ʱ�ڵ�ָ��
	if(root!=NULL)
	{                               //�����ڵ����
		rear=(rear+1)%Max;      		
		q[rear]=root;
	}
	while(front!=rear){
		front=(front+1)%Max;
		p=q[front];                 //ɾ�����׵�Ԫ�� �������ڵ㣨���ҽڵ㣩����
		printf("%c",p->data);  //���������Ԫ�ص�ֵ
		if(p->left!=null)
		{                 //����������ӽڵ㣬�����ӽڵ�������
			rear=(rear+1)%Max;
			q[rear]=p->left;
        }
		if(p->right!=null)
		{             //��������Һ��ӽڵ㣬���Һ��ӽڵ�������   
			rear=(rear+1)%Max;
			q[rear]=p->right;
		}
  }
}

*/
//������
int main(){
	BinTree root;
	int i,depth;
	char* str = "A(B(D(G)),C(E,F))";
	printf("\n");
	printf("Creat Bin_Tree�� Input preorder:"); //������ȫ����������������
	// ��#�������㣬��ABD###CE##F##


	root=CreatBinTree(str);       //���������������ظ����
	do{                    //�Ӳ˵���ѡ�������ʽ��������š�
		printf("\t********** select ************\n");
		printf("\t1: Preorder Traversal\n");    
		printf("\t2: Iorder Traversal\n");
		printf("\t3: Postorder traversal\n");
		printf("\t4: PostTreeDepth,Node number,Leaf number\n");
		printf("\t0: Exit\n");		
		printf("\t*******************************\n");
		scanf("%d",&i);    //����˵���ţ�0-4��
		switch (i)
		{
		case 1:
			printf("Print Bin_tree Preorder: ");
			Preorder1(root);      //�������
			break;
		case 2: printf("Print Bin_Tree Inorder: ");
			MorrisInorder(root);      //�������
			break;
		case 3: printf("Print Bin_Tree Postorder: ");
			Postorder1(root);    //�������
			break;
		case 4: depth=TreeDepth(root);     //��������ȼ�Ҷ����
			printf("BinTree Depth=%d  BinTree Node number=%d",depth,NodeNum);
			printf("  BinTree Leaf number=%d",leaf);
			break;
//		case 5: printf("LevePrint Bin_Tree: ");
//			Levelorder(root);     //����α���
//			break;
		default: exit(1);
		}
		printf("\n");
	}while(i!=0);
}


