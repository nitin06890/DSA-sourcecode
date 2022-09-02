// OJ: https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

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
class Solution
{
public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node *head)
    {
        Node *fast = head, *slow = head;
        while (fast->next && fast->next->next)
        {
            Node *prev = fast->next;
            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow)
            {
                slow = head;
                // now slow and fast point to starting point of loop
                while (slow != fast)
                {
                    prev = fast;
                    fast = fast->next;
                    slow = slow->next;
                }
                prev->next = NULL;
                break;
            }
        }
    }
};