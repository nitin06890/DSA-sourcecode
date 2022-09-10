// OJ: https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

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

class Solution
{
public:
    Node *reverse(Node *head)
    {
        Node *prev = NULL, *curr = head, *frwd = NULL;
        while (curr != NULL)
        {
            frwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = frwd;
        }
        return prev;
    }

    Node *addHelper(Node *head)
    {
        Node *res = head;
        Node *temp;
        int carry = 1, sum = 0;
        while (head != NULL)
        {
            sum = carry + head->data;
            carry = (sum >= 10) ? 1 : 0;
            sum = sum % 10;
            head->data = sum;
            temp = head;
            head = head->next;
        }
        if (carry > 0)
            temp->next = new Node(carry);
        return res;
    }

    Node *addOne(Node *head)
    {
        head = reverse(head);
        head = addHelper(head);
        head = reverse(head);
        return head;
    }
};