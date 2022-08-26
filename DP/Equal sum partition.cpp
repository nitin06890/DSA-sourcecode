// OJ: https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> dp;

    bool isSubsetSum(int arr[], int sum, int n)
    {
        if (sum == 0)
            return 1;
        dp.resize(n + 1, vector<int>(sum + 1));
        for (int i = 0; i < n + 1; i++)
            dp[i][0] = 0;
        for (int j = 0; j < n + 1; j++)
            dp[0][j] = 1;

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {
                if (arr[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][sum];
    }

    int equalPartition(int n, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i];
        if (sum % 2 != 0)
            return false;
        else if (sum % 2 == 0)
            return isSubsetSum(arr, sum / 2, n);
    }
};