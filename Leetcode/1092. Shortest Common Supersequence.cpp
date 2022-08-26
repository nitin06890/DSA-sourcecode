// OJ: https://leetcode.com/problems/shortest-common-supersequence/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> dp{1001, vector<int>(1001, 0)};

    void lcs(string s1, string s2, int m, int n)
    {
        for (int i = 1; i < m + 1; i++)
            for (int j = 1; j < n + 1; j++)
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        return;
    }

    string shortestCommonSupersequence(string s1, string s2)
    {
        int m = s1.size(), n = s2.size();
        lcs(s1, s2, m, n);
        string ans = "";
        int i = m, j = n;
        while (i > 0 && j > 0)
        {
            if (s1[i - 1] == s2[j - 1])
                ans.push_back(s1[i - 1]), i--, j--;
            else if (dp[i][j - 1] > dp[i - 1][j])
                ans.push_back(s2[j - 1]), j--;

            else
                ans.push_back(s1[i - 1]), i--;
        }
        while (i > 0)
            ans.push_back(s1[i - 1]), i--;
        while (j > 0)
            ans.push_back(s2[j - 1]), j--;
        reverse(ans.begin(), ans.end());
        return ans;
    }
};