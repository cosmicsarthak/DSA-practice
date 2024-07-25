#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void levelorder(Node *node) // left root right
{
}
void inorder(Node *node) // left root right
{
    if (node == NULL)
        return;

    preorder(node->left);
    cout << (node->data);
    preorder(node->right);
}
void postorder(Node *node) // left right root
{
    if (node == NULL)
        return;

    preorder(node->left);
    preorder(node->right);
    cout << (node->data);
}
void preorder(Node *node) // root left right
{
    if (node == NULL)
        return;

    cout << (node->data);
    preorder(node->left);
    preorder(node->right);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->right = new Node(5);
    return 0;
}