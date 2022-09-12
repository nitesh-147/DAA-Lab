//1 How do you find the middle element of a singly linked list in one pass?

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

int middle(Node *root)
{
    Node *slow = root;
    Node *fast = root;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int main()
{
    Node *root;// = (Node *)malloc(sizeof(Node));
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

    cout << "Middle element: " << middle(root) << endl;
    return 0;
}