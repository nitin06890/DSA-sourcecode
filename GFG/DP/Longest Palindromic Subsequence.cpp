// OJ: https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int lcs(string &X, string &Y, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (X[i - 1] == Y[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }

public:
    int longestPalinSubseq(string A)
    {
        string B = A;
        reverse(B.begin(), B.end());
        return lcs(A, B, A.length(), B.length());
    }
};