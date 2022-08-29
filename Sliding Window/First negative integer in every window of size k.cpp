// OJ: https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

#include <bits/stdc++.h>
using namespace std;

#define int long long
vector<int> printFirstNegativeInteger(int a[], int n, int k)
{
    int i = 0, j = 0;
    vector<int> ans;
    list<int> l;

    while (j < n)
    {
        if (a[j] < 0)
            l.push_back(a[j]);
        if (j - i + 1 < k)
            j++;
        else if (j - i + 1 == k)
        {
            if (l.size() == 0)
                ans.push_back(0);
            else
                ans.push_back(l.front());
            if (a[i] < 0)
                l.pop_front();
            i++;
            j++;
        }
    }
    return ans;
}