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
BinTree CreatBinTree(void){
	BinTree T;
	char ch;
	if((ch=getchar())=='#')
		return(NULL);   //����#�����ؿ�ָ��
	else
	{
		T=(BinTNode *)malloc(sizeof(BinTNode));  //���ɽ��
		T->data=ch;
		T->lchild=CreatBinTree();        //����������
		T->rchild=CreatBinTree();        //����������
		return(T);
	}
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

//�������
void Inorder(BinTree T){
	if(T)
	{
		Inorder(T->lchild);      //�������������
		printf("%c",T->data);    //���ʽ��
		Inorder(T->rchild);      //�������������
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
	printf("\n");
	printf("Creat Bin_Tree�� Input preorder:"); //������ȫ����������������
	// ��#�������㣬��ABD###CE##F##
	root=CreatBinTree();       //���������������ظ����
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
			Preorder(root);      //�������
			break;
		case 2: printf("Print Bin_Tree Inorder: ");
			Inorder(root);      //�������
			break;
		case 3: printf("Print Bin_Tree Postorder: ");
			Postorder(root);    //�������
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


