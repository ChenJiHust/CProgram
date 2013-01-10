
typedef struct node{
	int data;
	struct node *lchild,*rchild;
}BSTNode;            //自定义二叉树的结点类型

typedef BSTNode *BST;

BST insert(BST tree,int data);
BST search(const BST node,int data);