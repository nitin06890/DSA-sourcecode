// OJ: https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};

// Iterative
class Solution
{
public:
    // Function to reverse a linked list.
    Node *reverseList(Node *head)
    {
        Node *prev = NULL, *curr = head, *frwd = NULL;
        while (curr != NULL)
        {
            frwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = frwd;
        }
        head = prev;
        return head;
    }
};
//recursive
