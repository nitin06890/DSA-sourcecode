// OJ: https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

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
private:
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

public:
    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {

        first = reverse(first);
        second = reverse(second);

        Node *head = new Node(0), *curr = head;
        int carry = 0;

        while (first != NULL || second != NULL || carry == 1)
        {
            int sum = 0;
            if (first)
                sum += first->data, first = first->next;
            if (second)
                sum += second->data, second = second->next;
            sum += carry;
            carry = sum / 10;
            sum %= 10;

            Node *temp = new Node(sum);
            curr->next = temp;
            curr = curr->next;
        }
        return reverse(head->next);
    }
};