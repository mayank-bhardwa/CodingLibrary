#include <iostream>
#define deb(a) cout<<#a<<" "<<a<<" ";
using namespace std;

struct Node{
	int data;
	Node *lchild , *rchild;
	int height;

	Node(int data)
	{
		this->data = data;
		lchild = NULL;
		rchild = NULL;
		height=1;
	}
};

class AVL
{
	private:
		Node *root=NULL;
		int height(Node*);
		int balance(Node*);
		void inorder(Node*);
		Node* rightRotate(Node *node);
		Node* leftRotate(Node *node);		
		Node* insert(Node*,int);
	public:
		void insert(int data)
		{
			root=insert(root,data);
		}
		void inorder()
		{
			inorder(root);
		}
};

Node* AVL::rightRotate(Node *node)
{
	Node *temp1 = node->lchild;
	Node *temp2 = temp1->rchild;
	temp1->rchild=node;
	node->lchild=temp2;

	if(temp2 != NULL)	temp2->height = 1+max( height(temp2->lchild), height(temp2->rchild));
	if(temp1 != NULL)	temp1->height = 1+max( height(temp1->lchild), height(temp1->rchild));

	return temp1;
}

Node* AVL::leftRotate(Node *node)
{
	Node *temp1 = node->rchild;
	Node *temp2 = temp1->lchild;
	temp1->lchild = node;
	node->rchild = temp2;

	if(temp2 != NULL)	temp2->height = 1+max( height(temp2->lchild), height(temp2->rchild));
	if(temp1 != NULL)	temp1->height = 1+max( height(temp1->lchild), height(temp1->rchild));

	return temp1;
}

int AVL::height(Node *node)
{
	if(node == NULL)return 0;
	return node->height;
}

int AVL::balance(Node *node)
{
	if(node == NULL)return 0;
	return height(node->lchild) - height(node->rchild) ;
}

void AVL::inorder(Node *node)
{
	if(node == NULL) return ;
	inorder(node->lchild);
	cout<<node->data<<" ";
	inorder(node->rchild);
}

Node* AVL::insert(Node *node,int data)
{
	if(node == NULL)return new Node(data);
	if(node->data > data)
	{
		node->lchild = insert(node->lchild,data);
	}
	else
	{
		node->rchild = insert(node->rchild,data);
	}

	node->height = max( height(node->lchild), height(node->rchild)) + 1;

	int b = balance(node);

	if(b>1)
	{
		if(data < node->lchild->data) return rightRotate(node);
		else 
		{
			node->lchild = leftRotate(node->lchild);
			return  rightRotate(node);
		}
	}

	if(b<-1)
	{
		if(data < node->rchild->data)
		{
			node->rchild = rightRotate(node->rchild);
			return leftRotate(node);
		}
		else
		{
			return leftRotate(node);
		}
	}

	return node;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k;
	AVL avl;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>k;
		avl.insert(k);
	}
	avl.inorder();
	return 0;
}