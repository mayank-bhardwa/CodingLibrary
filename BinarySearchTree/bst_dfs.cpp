#include <iostream>
#include <stack>
using namespace std;

template <class T>
class BST
{
    protected :
        struct Node
        {
            T data;
            struct Node *left,*right;
        };
        Node *root;
    public : 
        void insert(T data)
        {
            root=insert(root,data);
        }
        void DFS()
        {
            DFS(root);
        }
        BST()
        {
            root=NULL;
        }
    private :
        Node* newNode(T data)
        {
            Node *temp=new Node;
            temp->data=data;
            temp->left=NULL;
            temp->right=NULL;
            return temp;
        }
        Node* insert(Node *root,T data)
        {
            if(root==NULL)  return  newNode(data);
            else if( root->data > data )
                root->left=insert(root->left,data);
            else if( root->data < data )
                root->right=insert(root->right,data);
            return root;
        }

        void DFS(Node *root)
        {
            stack<T> dfs;
            dfs.push(root->data);
            while(root->left)
            {
                dfs.push(root->left);
            }
        }
};

int main(int argc, char const *argv[])
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    BST<int> btree;
    btree.insert(50);
    btree.insert(30);
    btree.insert(20);
    btree.insert(40);
    btree.insert(70);
    btree.insert(60);
    btree.insert(80);

    return 0;
}
