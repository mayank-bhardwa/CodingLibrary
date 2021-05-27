#include <iostream>
#include <cinttypes>
using namespace std;

struct Node
{
    int data;
    Node *addr;
    Node(int data)
    {
        this->data = data;
        this->addr = NULL;
    }
};

class DoublyList
{
private:
    Node *head, *tail;
    Node *XOR(Node *p, Node *n)
    {
        return reinterpret_cast<Node *>(
            reinterpret_cast<uintptr_t>(p) ^ reinterpret_cast<uintptr_t>(n));
    }

public:
    DoublyList()
    {
        this->head = NULL;
        this->tail = NULL;
    }

    void insert(int data)
    {
        Node *temp = new Node(data);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            Node *tailpre = XOR(tail->addr, NULL);
            tail->addr = XOR(tailpre, temp);
            temp->addr = XOR(tail, NULL);
            tail = temp;
        }
    }

    void fTraverse()
    {
        Node *curr = head, *prev = NULL, *next = NULL;
        while (curr != NULL)
        {
            cout << curr->data << " ";
            next = XOR(prev, curr->addr);
            prev = curr;
            curr = next;
        }
    }

    void bTraverse()
    {
        Node *curr = tail, *pre = NULL, *next = NULL;
        while (curr != NULL)
        {
            cout << curr->data << " ";
            next = XOR(curr->addr, pre);
            pre = curr;
            curr = next;
        }
    }
};

int main()
{
    DoublyList list;
    list.insert(15);
    list.insert(78);
    list.insert(42);
    list.insert(36);
    list.insert(12);
    list.fTraverse();
    cout << endl;
    list.bTraverse();
    return 0;
}