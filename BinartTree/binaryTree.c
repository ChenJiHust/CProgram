#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define Max 20         //结点的最大个数

typedef struct node{
	char data;
	struct node *lchild,*rchild;
}BinTNode;            //自定义二叉树的结点类型

typedef BinTNode *BinTree;    //定义二叉树的指针

int NodeNum,leaf;   //NodeNum为结点数，leaf为叶子数
//基于先序遍历算法创建二叉树

//要求输入先序序列，其中加入虚结点"#"以示空指针的位置
BinTree CreatBinTree(void){
	BinTree T;
	char ch;
	if((ch=getchar())=='#')
		return(NULL);   //读入#，返回空指针
	else
	{
		T=(BinTNode *)malloc(sizeof(BinTNode));  //生成结点
		T->data=ch;
		T->lchild=CreatBinTree();        //构造左子树
		T->rchild=CreatBinTree();        //构造右子树
		return(T);
	}
}

//先序遍历
void Preorder(BinTree T){
	if(T)
	{
		printf("%c",T->data);    //访问结点
		Preorder(T->lchild);    //先序遍历左子树
		Preorder(T->rchild);    //先序遍历右子树
	}
}

//中序遍历
void Inorder(BinTree T){
	if(T)
	{
		Inorder(T->lchild);      //中序遍历左子树
		printf("%c",T->data);    //访问结点
		Inorder(T->rchild);      //中序遍历右子树
	}
}

//后序遍历
void Postorder(BinTree T){
	if(T)
	{
		Postorder(T->lchild);    //后序遍历左子树
		Postorder(T->rchild);    //后序遍历右子树
		printf("%c",T->data);    //访问结点
	}
}

//采用后序遍历求二叉树的深度、结点数及叶子数的递归算法
int TreeDepth(BinTree T){
	int hl,hr,max;
	if(T)
	{
		hl=TreeDepth(T->lchild);   	//求左深度
		hr=TreeDepth(T->rchild);    //求右深度
		max=hl>hr? hl:hr;           //取左右深度的最大值
		NodeNum=NodeNum+1;         //求结点数
		if(hl==0&&hr==0) 
			leaf=leaf+1;           //若左右深度为0，即为叶子。
		return(max+1);
	}
	else
		return(0);
}
/*
//按层遍历
Levelorder( BinTNode *root){
	BinTNode * q[Max];          //定义BinTNode类型的队列 用于存放节点 队列长最大为20个元素
	int front=0,rear=0;                  //初始化队列为空
	BinTNode *p;                          //临时节点指针
	if(root!=NULL)
	{                               //将根节点进队
		rear=(rear+1)%Max;      		
		q[rear]=root;
	}
	while(front!=rear){
		front=(front+1)%Max;
		p=q[front];                 //删除队首的元素 让两个节点（左右节点）孤立
		printf("%c",p->data);  //输出队列首元素的值
		if(p->left!=null)
		{                 //如果存在左孩子节点，则左孩子节点进入队列
			rear=(rear+1)%Max;
			q[rear]=p->left;
        }
		if(p->right!=null)
		{             //如果存在右孩子节点，则右孩子节点进入队列   
			rear=(rear+1)%Max;
			q[rear]=p->right;
		}
  }
}

*/
//主函数
int main(){
	BinTree root;
	int i,depth;
	printf("\n");
	printf("Creat Bin_Tree； Input preorder:"); //输入完全二叉树的先序序列
	// 用#代表虚结点，如ABD###CE##F##
	root=CreatBinTree();       //创建二叉树，返回根结点
	do{                    //从菜单中选择遍历方式，输入序号。
		printf("\t********** select ************\n");
		printf("\t1: Preorder Traversal\n");    
		printf("\t2: Iorder Traversal\n");
		printf("\t3: Postorder traversal\n");
		printf("\t4: PostTreeDepth,Node number,Leaf number\n");
		printf("\t0: Exit\n");		
		printf("\t*******************************\n");
		scanf("%d",&i);    //输入菜单序号（0-4）
		switch (i)
		{
		case 1:
			printf("Print Bin_tree Preorder: ");
			Preorder(root);      //先序遍历
			break;
		case 2: printf("Print Bin_Tree Inorder: ");
			Inorder(root);      //中序遍历
			break;
		case 3: printf("Print Bin_Tree Postorder: ");
			Postorder(root);    //后序遍历
			break;
		case 4: depth=TreeDepth(root);     //求树的深度及叶子数
			printf("BinTree Depth=%d  BinTree Node number=%d",depth,NodeNum);
			printf("  BinTree Leaf number=%d",leaf);
			break;
//		case 5: printf("LevePrint Bin_Tree: ");
//			Levelorder(root);     //按层次遍历
//			break;
		default: exit(1);
		}
		printf("\n");
	}while(i!=0);
}


