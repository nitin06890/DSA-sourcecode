// OJ: https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

#include <bits/stdc++.h>
using namespace std;

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