// 7

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

void delete_duplicate(Node *&root)
{
    if (root == NULL || root->next == NULL)
        return;
    Node *prev = root, *curr;
    unordered_map<int, int> m;
    m[root->data]++;
    while (prev != NULL)
    {
        curr = prev->next;
        if (m[curr->data] == 1)
        {
            prev->next = curr->next;
            delete (curr);
        }
        else
        {
            m[curr->data]++;
        }
        prev = prev->next;
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
    delete_duplicate(root);
    print(root);

    return 0;
}