#include <iostream>
#include <stack>
using namespace std;

enum Colour
{
    Red,
    Black
};

struct Node
{
    int data;
    bool Colour; // 0-Red 1-Black
    Node *lchild, *rchild;

    Node(int data)
    {
        this->data = data;
        this->Colour = Red; // newly created Node is red
        this->lchild = NULL;
        this->rchild = NULL;
    }
};

class RedBlackTree
{
private:
    Node *head;

public:
    RedBlackTree()
    {
        head = NULL;
    }

    void insert(int data);
    // {
    //     head = insert(head, data);
    // }

    void print();

protected:
    Node *insert(Node *head, int data);
};

int main()
{
    RedBlackTree rbt;
    rbt.insert(5);
    rbt.insert(2);
    rbt.insert(7);
    rbt.insert(6);
    rbt.insert(4);
    rbt.print();
    return 0;
}

void RedBlackTree::insert(int data)
{
    Node *temp = head;
    Node *node = new Node(data);
    stack<Node *> S;
    S.push(temp);
    while(true)
    {
        while(data < temp->data)
        {
            temp = temp->lchild;
        }

        if(data)
        {
            
        }
    }
}

void RedBlackTree::print()
{
    stack<Node *> S;
    Node *temp = head;
    S.push(temp);

    while (!S.empty())
    {
        while (temp->lchild != NULL)
        {
            temp = temp->lchild;
            S.push(temp);
        }

        temp = S.top();
        S.pop();
        cout << temp->data << " ";
        if (temp->rchild != NULL)
        {
            temp = temp->rchild;
            S.push(temp);
        }
    }
}