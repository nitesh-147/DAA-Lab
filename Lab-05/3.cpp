// 3.

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

int third_from_last(Node *root)
{
    if (root == NULL || root->next == NULL || root->next->next == NULL)
        return -1;
    Node *temp = root;

    while (temp->next->next->next != NULL)
    {
        temp = temp->next;
    }
    return temp->data;
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

    cout << "Third Node from Last: " << third_from_last(root) << endl;
    return 0;
}