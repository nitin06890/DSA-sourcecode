// OJ: https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int minSubsetSum(int arr[], int n, int r)
    {
        bool dp[n + 1][r + 1];
        for (int i = 0; i < r + 1; i++)
            dp[0][i] = 0;
        for (int i = 0; i < n + 1; i++)
            dp[i][0] = 1;

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < r + 1; j++)
            {
                if (arr[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        int mn = INT_MAX;
        for (int i = 0; i <= r / 2; i++)
            if (dp[n][i])
                mn = min(mn, r - 2 * i);
        return mn;
    }

public:
    int minDifference(int arr[], int n)
    {
        int range = 0;
        for (int i = 0; i < n; i++)
            range += arr[i];
        return minSubsetSum(arr, n, range);
    }
};