// OJ: https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> dp;
    int mcm(int arr[], int i, int j)
    {
        if (i >= j)
            return 0;
        if (dp[i][j] != 0)
            return dp[i][j];
        int mn = INT_MAX;
        for (int k = i; k < j; k++)
        {
            int tempans = mcm(arr, i, k) + mcm(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
            mn = min(mn, tempans);
        }
        return dp[i][j] = mn;
    }

    int matrixMultiplication(int n, int arr[])
    {
        dp.assign(n + 1, vector<int>(n + 1, 0));
        return mcm(arr, 1, n - 1);
    }
};