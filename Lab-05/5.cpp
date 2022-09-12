// 5

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        this->data = x;
        this->next = NULL;
    }
};

void insert(Node *&root, int x)
{
    if (root == NULL)
        root = new Node(x);

    else
    {
        Node *temp = root;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new Node(x);
    }
}

void print(Node *root)
{

    Node *temp = root;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void partition(Node *&head, int x)
{
    if (head == NULL || head->next == NULL)
        return;
    Node *a = head, *b = head;
    while (b != NULL)
    {
        if (b->data < x)
        {
            swap(a->data, b->data);
            a = a->next;
            b = b->next;
        }
        else
        {
            b = b->next;
        }
    }
}

int main()
{
    Node *root = (Node *)malloc(sizeof(Node));
    root = NULL;

    cout << " Size of linked list (no. of elements) :" << endl;
    int n;
    cin >> n;

    cout << "Enter " << n << " Elements" << endl;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insert(root, x);
    }
    print(root);
    partition(root, 4);
    print(root);

    return 0;
}