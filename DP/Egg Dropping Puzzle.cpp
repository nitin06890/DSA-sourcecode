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
            // int tempans = 1 + max(solve(e, f-k), solve(e-1, k-1));
            int low, high;
            if (dp[e][f - k] != 0)
                low = dp[e][f - k];
            else
            {
                low = solve(e, f - k);
                dp[e][f - k] = low;
            }
            if (dp[e - 1][k - 1] != 0)
                high = dp[e - 1][k - 1];
            else
            {
                high = solve(e - 1, k - 1);
                dp[e - 1][k - 1] = high;
            }
            int tempans = 1 + max(low, high);
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