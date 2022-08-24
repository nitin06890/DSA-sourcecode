// OJ: https://leetcode.com/problems/coin-change/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int sum)
    {
        int n = coins.size();
        long long int dp[n + 1][sum + 1];

        for (int i = 0; i < n + 1; i++)
            dp[i][0] = 0;
        for (int j = 0; j < sum + 1; j++)
            dp[0][j] = INT_MAX - 1;
        for (int j = 1; j < sum + 1; j++)
        {
            if (j % coins[0] == 0)
                dp[1][j] = j / coins[0];
            else
                dp[1][j] = INT_MAX - 1;
        }

        for (int i = 2; i < n + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {
                if (coins[i - 1] <= j)
                    dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        if (dp[n][sum] == INT_MAX - 1)
            return -1;
        return dp[n][sum];
    }
};