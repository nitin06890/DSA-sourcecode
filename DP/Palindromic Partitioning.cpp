// OJ: https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> dp;
    bool isPalindrome(string s, int i, int j)
    {
        if (i >= j)
            return true;
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    int solve(string s, int i, int j)
    {
        if (i >= j)
            return 0;
        if (isPalindrome(s, i, j) == true)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int mn = INT_MAX;
        for (int k = i; k < j; k++)
        {
            // int tempans = 1 + solve(s, i, k) + solve(s, k+1, j);
            int left, right;
            if (dp[i][k] != -1)
                left = dp[i][k];
            else
                left = solve(s, i, k), dp[i][k] = left;
            if (dp[k + 1][j] != -1)
                right = dp[k + 1][j];
            else
                right = solve(s, k + 1, j), dp[k + 1][j] = right;
            int tempans = 1 + left + right;
            mn = min(mn, tempans);
        }
        return dp[i][j] = mn;
    }

    int palindromicPartition(string str)
    {
        int n = str.size();
        dp.assign(n + 1, vector<int>(n + 1, -1));
        return solve(str, 0, n - 1);
    }
};