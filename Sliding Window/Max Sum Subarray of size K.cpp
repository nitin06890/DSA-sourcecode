// OJ: https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long maximumSumSubarray(int k, vector<int> &arr, int n)
    {
        int i = 0, j = 0;
        long sum = 0;
        long mx = 0;
        while (j < n)
        {
            sum += arr[j];
            if (j - i + 1 < k)
                j++;
            else if (j - i + 1 == k)
            {
                mx = max(mx, sum);
                sum -= arr[i];
                j++;
                i++;
            }
        }
        return mx;
    }
};