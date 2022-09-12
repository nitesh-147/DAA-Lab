//2
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

void create_cycle(Node *&root)
{
    Node *temp = root;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = root;
}
bool detectcycle(Node *root)
{
    Node *slow = root;
    Node *fast = root;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }
    return false;
}

int firstnode_cycle(Node *root)
{
    Node *slow = root;
    Node *fast = root;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    int k = 1;
    while (fast->next != slow)
    {
        fast = fast->next;
        k++;
    }
    fast = root, slow = root;
    // k++;
    while (k--)
    {
        fast = fast->next;
    }
    while (fast != slow)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow->data;
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

    create_cycle(root);
    if (detectcycle(root))
    {
        cout << "Cycle is present from ";
        cout << firstnode_cycle(root);
    }
    else
    {
        cout << "Cycle is not present" << endl;
    }

    return 0;
}