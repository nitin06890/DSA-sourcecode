// OJ: https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node *h1, Node *h2)
{
    while (h1)
    {
        h1->data = h1->data + 10000;
        h1 = h1->next;
    }
    while (h2)
    {
        if (h2->data > 1000)
            return (h2->data) - 10000;
        h2 = h2->next;
    }
    return -1;
};