
typedef struct node{
	int data;
	struct node *lchild,*rchild;
}BSTNode;            //�Զ���������Ľ������

typedef BSTNode *BST;

BST insert(BST tree,int data);
BST search(const BST node,int data);