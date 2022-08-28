// OJ: https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> dp;

    int solve(int e, int f)
    {
        if (f == 0 || f == 1)
            return f;
        if (e == 1)
            return f;
        if (dp[e][f] != 0)
            return dp[e][f];
        int mn = INT_MAX;
        for (int k = 1; k <= f; k++)
        {
            int tempans = 1 + max(solve(e, f - k), solve(e - 1, k - 1));
            mn = min(mn, tempans);
        }
        return dp[e][f] = mn;
    }

public:
    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int eggDrop(int e, int f)
    {
        dp.assign(e + 1, vector<int>(f + 1, 0));
        return solve(e, f);
    }
};