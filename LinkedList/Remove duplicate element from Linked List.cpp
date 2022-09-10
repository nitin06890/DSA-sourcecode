// OJ: https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1

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

// sorted list

Node *removeDuplicates(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *curr = head;

    while (curr->next != NULL)
    {
        if (curr->data == curr->next->data)
            curr->next = curr->next->next;
        else
            curr = curr->next;
    }
    return head;
}

// unsorted list

class Solution
{
public:
    // Function to remove duplicates from unsorted linked list.
    Node *removeDuplicates(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        Node *curr = head;
        unordered_set<int> st;

        while (curr->next != NULL)
        {
            st.insert(curr->data);
            if (st.find(curr->next->data) != st.end())
                curr->next = curr->next->next;
            else
                curr = curr->next;
        }
        return head;
    }
};