// OJ: https://practice.geeksforgeeks.org/problems/quick-sort-on-linked-list/1

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
};

// you have to complete this function

void swapVal(node *n1, node *n2)
{
    int temp;
    temp = n1->data;
    n1->data = n2->data;
    n2->data = temp;
}

node *partition(node *s, node *e)
{
    int pivot = s->data;
    node *i = s;
    node *j = s->next;

    while (j != e)
    {
        if (j->data < pivot)
        {
            i = i->next;
            swapVal(i, j);
        }
        j = j->next;
    }
    swapVal(i, s);
    return i;
}

void quickSortHelper(node *s, node *e)
{
    if (s != e)
    {
        node *pivot = partition(s, e);
        quickSortHelper(s, pivot);
        quickSortHelper(pivot->next, e);
    }
}

void quickSort(struct node **head)
{
    // start -- end
    quickSortHelper(*head, NULL);
}