// OJ: https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mod = 1003;
    unordered_map<string, int> dp;
    int solve(string &s, int i, int j, bool isTrue)
    {
        if (i > j)
            return 0;
        if (i == j)
        {
            if (isTrue == true)
                return s[i] == 'T';
            else
                return s[i] == 'F';
        }
        // create key
        string temp = to_string(i) + " " + to_string(j) + " " + to_string(isTrue);
        if (dp.find(temp) != dp.end())
            return dp[temp];

        // create value
        int ans = 0;
        for (int k = i + 1; k < j; k += 2)
        {
            int lt = solve(s, i, k - 1, true);
            int lf = solve(s, i, k - 1, false);
            int rt = solve(s, k + 1, j, true);
            int rf = solve(s, k + 1, j, false);

            if (s[k] == '&')
            {
                if (isTrue == true)
                    ans += lt * rt;
                else
                    ans += lt * rf + lf * rt + lf * rf;
            }
            else if (s[k] == '|')
            {
                if (isTrue == true)
                    ans += lt * rt + lt * rf + lf * rt;
                else
                    ans += lf * rf;
            }
            else if (s[k] == '^')
            {
                if (isTrue == true)
                    ans += lt * rf + lf * rt;
                else
                    ans += lt * rt + lf * rf;
            }
        }
        return dp[temp] = ans % mod;
    }

    int countWays(int n, string s)
    {
        dp.clear();
        return solve(s, 0, n - 1, true) % mod;
    }
};