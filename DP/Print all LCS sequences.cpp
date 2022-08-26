// OJ: https://practice.geeksforgeeks.org/problems/print-all-lcs-sequences3413/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int lcs(string s, string t)
    {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }

    set<string> st;
    void solve(string s, string t, int i, int j, string &temp, vector<string> &ans, int cnt)
    {
        if (cnt == 0)
        {
            if (st.find(temp) == st.end())
            {
                st.insert(temp);
                ans.push_back(temp);
            }
            return;
        }
        if (i >= s.size() || j >= t.size())
            return;
        for (int r = i; r < s.size(); r++)
        {
            for (int c = j; c < t.size(); c++)
            {
                if (s[r] == t[c])
                {
                    temp.push_back(s[r]);
                    solve(s, t, r + 1, c + 1, temp, ans, cnt - 1);
                    temp.pop_back(); // backtrack
                }
            }
        }
    }

public:
    vector<string> all_longest_common_subsequences(string s, string t)
    {
        int cnt = lcs(s, t);
        vector<string> ans;
        string temp = "";
        solve(s, t, 0, 0, temp, ans, cnt);
        sort(ans.begin(), ans.end());
        return ans;
    }
};