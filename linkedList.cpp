// #include <bits/stdc++.h>
// using namespace std;
// #define DUMMYVALUE INT_MIN
// int len = 0;
// class LinkedListNode
// {
// public:
//     int value;
//     LinkedListNode *next;
//     LinkedListNode(int val, LinkedListNode *nxt)
//     {
//         value = val;
//         next = nxt;
//     }
// };

// LinkedListNode *insertAtHead(LinkedListNode *head, int val)
// {
//     LinkedListNode *newNode = new LinkedListNode(val, NULL);
//     LinkedListNode *prevHeadNext = head->next;
//     head->next = newNode;
//     newNode->next = prevHeadNext;
//     len++;
//     return head;
// }
// LinkedListNode *insertAtTail(LinkedListNode *head, int val)
// {
//     LinkedListNode *curr = head;
//     while (curr->next)
//     {
//         curr = curr->next;
//     }
//     curr->next = new LinkedListNode(val, NULL);
//     len++;
//     return head;
// }
// void insertAtIndex(LinkedListNode *head, int index, int val)
// {
//     if (index < 0 || index > len)
//         return;
//     auto curr = head;
//     while (index--)
//     {
//         curr = curr->next;
//     }
//     auto jointNode = curr->next;
//     curr->next = new LinkedListNode(val, NULL);
//     curr->next->next = jointNode;
//     len++;
// }
// void deleteAtIndex(LinkedListNode *head, int index)
// {
//     if (index < 0 || index >= len)
//         return;
//     auto curr = head;
//     while (index--)
//     {
//         curr = curr->next;
//     }
//     auto dumpNode = curr->next;
//     curr->next = curr->next->next;
//     delete (dumpNode);
//     len--;
// }
// void printList(LinkedListNode *head)
// {
//     LinkedListNode *curr = head->next;
//     while (curr)
//     {
//         cout << curr->value << " ";
//         curr = curr->next;
//     }
// }
// int main()
// {
//     LinkedListNode *head = new LinkedListNode(DUMMYVALUE, NULL);

//     for (int i = 0; i < 5; i++)
//     {
//         head = insertAtHead(head, i);
//     }
//     for (int i = 5; i < 10; i++)
//     {
//         head = insertAtTail(head, i);
//     }
//     insertAtIndex(head, 6, 16);
//     deleteAtIndex(head, 5);
//     printList(head);
// }

// linked list insertion
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void insertAtHead(Node *&head, int data)
{
    if (head == NULL)
    {
        head = new Node(data);
        return;
    }
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}
void insertAtIndex(Node *&head, int data, int idx)
{
    if (idx == 0)
        insertAtHead(head, data);
    else
    {
        Node *temp = head;
        for (int i = 0; i < idx - 1; i++)
        {
            temp = temp->next;
        }
        Node *newNode = new Node(data);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}
Node *recReverseLL(Node *&head)
{
    // base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *smallHead = recReverseLL(head->next);
    head->next->next = head;
    head->next = NULL;
    return smallHead;
}
void iterativeReverseLL(Node *&head)
{
    Node *prev = NULL;
    Node *current = head;
    Node *temp;

    while (current != NULL)
    {
        temp = current->next;
        current->next = prev;

        prev = current;
        current = temp;
    }
    head = prev;
    return;
}
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
}
int main()
{
    Node *head = NULL;
    insertAtHead(head, 1);
    insertAtHead(head, 12);
    insertAtHead(head, 23);
    insertAtHead(head, 2);
    insertAtHead(head, 22);
    insertAtHead(head, 32);
    insertAtIndex(head, 34, 2);
    insertAtIndex(head, 35, 0);

    // head = recReverseLL(head);
    iterativeReverseLL(head);
    print(head);
}