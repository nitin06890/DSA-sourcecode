// OJ: https://leetcode.com/problems/scramble-string/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<string, int> dp;
    bool solve(string s1, string s2)
    {
        if (s1 == s2)
            return true;

        string key = s1 + ' ' + s2;
        if (dp.find(key) != dp.end())
            return dp[key];

        int n = s1.size();
        bool flag = false;
        for (int i = 1; i < n; i++)
        {
            bool condition1 = solve(s1.substr(0, i), s2.substr(0, i)) &&
                              solve(s1.substr(i, n - i), s2.substr(i, n - i));

            bool condition2 = solve(s1.substr(0, i), s2.substr(n - i, i)) &&
                              solve(s1.substr(i, n - i), s2.substr(0, n - i));

            if (condition1 || condition2)
            {
                flag = true;
                break;
            }
        }
        return dp[key] = flag;
    }

    bool isScramble(string s1, string s2)
    {
        return solve(s1, s2);
    }
};