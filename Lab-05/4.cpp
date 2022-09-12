// 4

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

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;

    TreeNode(int x)
    {
        this->data = x;
        this->left = NULL;
        this->right = NULL;
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

TreeNode *sortedListToBST(Node *head, Node *tail)
{
    if (head == tail)
        return NULL;
    if (head->next == tail)
    {
        TreeNode *root = new TreeNode(head->data);
        return root;
    }
    Node *mid = head, *temp = head;
    while (temp != tail && temp->next != tail)
    {
        mid = mid->next;
        temp = temp->next->next;
    }
    TreeNode *root = new TreeNode(mid->data);
    root->left = sortedListToBST(head, mid);
    root->right = sortedListToBST(mid->next, tail);
    return root;
}
void print_preorder(TreeNode *bst)
{
    if (bst == nullptr)
        return;

    cout << bst->data << " ";
    print_preorder(bst->left);
    print_preorder(bst->right);
}
void print_postorder(TreeNode *bst)
{
    if (bst == nullptr)
        return;

    print_postorder(bst->left);
    print_postorder(bst->right);
    cout << bst->data << " ";
}
void print_inorder(TreeNode *bst)
{
    if (bst == nullptr)
        return;

    print_inorder(bst->left);
    cout << bst->data << " ";
    print_inorder(bst->right);
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

    TreeNode *bst = sortedListToBST(root, NULL);
    print_preorder(bst);
    cout << endl;
    print_postorder(bst);
    cout << endl;
    print_inorder(bst);

    return 0;
}