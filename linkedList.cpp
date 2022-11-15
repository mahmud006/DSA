#include <bits/stdc++.h>
using namespace std;
#define DUMMYVALUE INT_MIN
int len = 0;
class LinkedListNode
{
public:
    int value;
    LinkedListNode *next;
    LinkedListNode(int val, LinkedListNode *nxt)
    {
        value = val;
        next = nxt;
    }
};

LinkedListNode *insertAtHead(LinkedListNode *head, int val)
{
    LinkedListNode *newNode = new LinkedListNode(val, NULL);
    LinkedListNode *prevHeadNext = head->next;
    head->next = newNode;
    newNode->next = prevHeadNext;
    len++;
    return head;
}
LinkedListNode *insertAtTail(LinkedListNode *head, int val)
{
    LinkedListNode *curr = head;
    while (curr->next)
    {
        curr = curr->next;
    }
    curr->next = new LinkedListNode(val, NULL);
    len++;
    return head;
}
void insertAtIndex(LinkedListNode *head, int index, int val)
{
    if (index < 0 || index > len)
        return;
    auto curr = head;
    while (index--)
    {
        curr = curr->next;
    }
    auto jointNode = curr->next;
    curr->next = new LinkedListNode(val, NULL);
    curr->next->next = jointNode;
    len++;
}
void deleteAtIndex(LinkedListNode *head, int index)
{
    if (index < 0 || index >= len)
        return;
    auto curr = head;
    while (index--)
    {
        curr = curr->next;
    }
    auto dumpNode = curr->next;
    curr->next = curr->next->next;
    delete (dumpNode);
    len--;
}
void printList(LinkedListNode *head)
{
    LinkedListNode *curr = head->next;
    while (curr)
    {
        cout << curr->value << " ";
        curr = curr->next;
    }
}
int main()
{
    LinkedListNode *head = new LinkedListNode(DUMMYVALUE, NULL);

    for (int i = 0; i < 5; i++)
    {
        head = insertAtHead(head, i);
    }
    for (int i = 5; i < 10; i++)
    {
        head = insertAtTail(head, i);
    }
    insertAtIndex(head, 6, 16);
    deleteAtIndex(head, 5);
    printList(head);
}