#include <bits/stdc++.h>
using namespace std;
#define DUMMYVALUE INT_MIN

class LinkedListNode
{
public:
    int value;
    LinkedListNode *left;
    LinkedListNode *right;
    LinkedListNode(int val)
    {
        value = val;
        left = right = NULL;
    }
};

void printPostorder(LinkedListNode *node)
{
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->value << " ";
}
void printInorder(LinkedListNode *node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->value << " ";
    printInorder(node->right);
}
void printPreorder(LinkedListNode *node)
{
    if (node == NULL)
        return;
    cout << node->value << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}
int main()
{
    LinkedListNode *head = new LinkedListNode(1);
    head->left = new LinkedListNode(2);
    head->right = new LinkedListNode(3);
    head->left->left = new LinkedListNode(4);
    head->left->right = new LinkedListNode(5);

    cout << "\nPreorder traversal of binary tree is \n";
    printPreorder(head);

    cout << "\nInorder traversal of binary tree is \n";
    printInorder(head);

    cout << "\nPostorder traversal of binary tree is \n";
    printPostorder(head);

    return 0;
}
