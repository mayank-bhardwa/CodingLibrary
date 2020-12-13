#include <iostream>
#include <queue>
using namespace std;

struct node
{
public:
    int data;
    struct node *lchild, *rchild;
    node(int data)
    {
        this->data = data;
        this->lchild = NULL;
        this->rchild = NULL;
    }
};

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->lchild);
        cout << root->data << "\t";
        inorder(root->rchild);
    }
}

void levelorder(node *root)
{
    if (root == NULL)
        return;
    int pl = 0;
    queue<node *> level;
    level.push(root);

    while (!level.empty())
    {
        node *temp = level.front();
        cout << temp->data << "\t";
        level.pop();

        if (temp->lchild != NULL)
            level.push(temp->lchild);

        if (temp->rchild != NULL)
            level.push(temp->rchild);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    node *root = new node(1);
    root->lchild = new node(2);
    root->rchild = new node(3);
    root->lchild->lchild = new node(4);
    root->lchild->rchild = new node(5);
    root->rchild->lchild = new node(6);
    root->rchild->rchild = new node(7);

    inorder(root);
    cout<<endl;
    levelorder(root);

    return 0;
}