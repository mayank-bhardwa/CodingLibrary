#include <iostream>
using namespace std;

/*
    Operations On Binary Search Tree
    Floor
    Ceil
    Greater
    Lower
    Insertion
    Deletion
*/

template <class T>
class BST
{
protected:
    struct Node
    {
        T data;
        struct Node *left, *right;
    };
    Node *root;

public:
    void insert(T data)
    {
        root = insert(root, data);
    }
    void inorder()
    {
        inorder(root);
    }
    void Delete(T data)
    {
        root = Delete(root, data);
    }
    BST()
    {
        root = NULL;
    }
    bool search(T data)
    {
        return search(root, data);
    }

private:
    Node *newNode(T data)
    {
        Node *temp = new Node;
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    Node *insert(Node *root, T data)
    {
        if (root == NULL)
            return newNode(data);
        else if (root->data > data)
            root->left = insert(root->left, data);
        else if (root->data < data)
            root->right = insert(root->right, data);
        return root;
    }
    bool search(Node *root, T data)
    {
        if (root == NULL)
            return false;
        else if (root->data == data)
            return true;
        else if (root->data > data)
            return search(root->left, data);
        else
            return search(root->right, data);
    }
    void inorder(Node *root)
    {
        if (root)
        {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }
    Node *inorderSuccessor(Node *node)
    {
        Node *temp = node;
        while (temp && temp->left)
            temp = temp->left;
        return temp;
    }
    Node *Delete(Node *root, T data)
    {
        if (root == NULL)
            return root;
        else if (root->data > data)
            root->left = Delete(root->left, data);
        else if (root->data < data)
            root->right = Delete(root->right, data);
        else
        {
            if (root->left && root->right)
            {
                Node *temp = inorderSuccessor(root->right);
                root->data = temp->data;
                root->right = Delete(root->right, temp->data);
            }
            else if (root->left)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            else
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
        }
        return root;
    }
};

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    BST<int> btree;
    btree.insert(50);
    btree.insert(30);
    btree.insert(20);
    btree.insert(40);
    btree.insert(70);
    btree.insert(60);
    btree.insert(80);
    btree.inorder();
    btree.Delete(20);
    cout << "\n";
    btree.inorder();
    btree.Delete(30);
    cout << "\n";
    btree.inorder();
    btree.Delete(50);
    cout << "\n";
    btree.inorder();
    cout << "\n"
         << btree.search(60) << " " << btree.search(20);
    return 0;
}
