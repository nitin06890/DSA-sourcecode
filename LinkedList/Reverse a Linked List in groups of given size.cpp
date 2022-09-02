// OJ: https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }

} * head;

class Solution
{
public:
    node *reverseHelper(node *head, int k)
    {
        if (head == NULL)
            return head;
        node *curr = head, *prev = NULL, *frwd = NULL;
        int cnt = 0;
        while (curr != NULL && cnt < k)
        {
            frwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = frwd;
            cnt++;
        }
        if (frwd != NULL)
        {
            head->next = reverse(frwd, k);
        }
        return prev;
    }

    struct node *reverse(struct node *head, int k)
    {
        return reverseHelper(head, k);
    }
};