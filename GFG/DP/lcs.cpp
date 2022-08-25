// OJ: https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int dp[1005][1005];

    int lcsHelper(int x, int y, string &s1, string &s2)
    {
        if (x == 0 || y == 0)
            return 0;
        if (dp[x][y] != -1)
            return dp[x][y];
        if (s1[x - 1] == s2[y - 1])
            return dp[x][y] = 1 + lcsHelper(x - 1, y - 1, s1, s2);
        else
            return dp[x][y] = max(lcsHelper(x - 1, y, s1, s2), lcsHelper(x, y - 1, s1, s2));
    }

public:
    // Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        memset(dp, -1, sizeof(dp));
        return lcsHelper(x, y, s1, s2);
    }
};

class Solution
{
public:
    // Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        int dp[x + 1][y + 1];

        for (int i = 0; i < x + 1; i++)
            dp[i][0] = 0;
        for (int i = 0; i < y + 1; i++)
            dp[0][i] = 0;
        for (int i = 1; i < x + 1; i++)
        {
            for (int j = 1; j < y + 1; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[x][y];
    }
};
