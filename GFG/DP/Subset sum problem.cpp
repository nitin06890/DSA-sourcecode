// OJ: https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

#include <bits/stdc++.h>
using namespace std;

// memoisation - top down

class Solution
{
public:
    vector<vector<int>> dp;

    bool isSubsetSumHelper(vector<int> &arr, int n, int sum)
    {
        if (sum == 0)
            return 1;
        if (n == 0)
            return 0;
        if (dp[n][sum] != -1)
            return dp[n][sum];

        if (arr[n - 1] <= sum)
            return dp[n][sum] = isSubsetSumHelper(arr, n - 1, sum - arr[n - 1]) || isSubsetSumHelper(arr, n - 1, sum);
        else
            return dp[n][sum] = isSubsetSumHelper(arr, n - 1, sum);
    }

    bool isSubsetSum(vector<int> arr, int sum)
    {
        int n = arr.size();
        dp.resize(n + 1, vector<int>(sum + 1, -1));
        return isSubsetSumHelper(arr, n, sum);
    }
};

// Tabulation - bottom up

class Solution
{
public:
    vector<vector<int>> dp;

    bool isSubsetSum(vector<int> arr, int sum)
    {
        if (sum == 0)
            return 1;
        int n = arr.size();
        dp.resize(n + 1, vector<int>(sum + 1));
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < sum + 1; j++)
            {
                if (i == 0)
                    dp[i][j] = 0;
                if (j == 0)
                    dp[i][j] = 1;
            }
        }
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
};