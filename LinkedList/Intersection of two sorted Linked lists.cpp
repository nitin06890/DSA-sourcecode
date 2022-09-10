// OJ: <https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node *findIntersection(Node *h1, Node *h2)
{
    Node *head1 = h1, *head2 = h2;
    Node *head = new Node(0);
    Node *curr = head;
    while (head1 && head2)
    {
        if (head1->data == head2->data)
        {
            curr->next = new Node(head1->data);
            curr = curr->next;
            head1 = head1->next;
            head2 = head2->next;
        }
        else if (head1->data > head2->data)
            head2 = head2->next;
        else
            head1 = head1->next;
    }
    return head->next;
}