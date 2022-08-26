// OJ: https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

#include <bits/stdc++.h>
using namespace std;

// memoisation - top down
class Solution
{
    int dp[1001][1001];

public:
    int knapSackHelper(int w, int wt[], int val[], int n)
    {
        if (n == 0 || w == 0)
            return 0; // base case
        if (dp[n][w] != -1)
            return dp[n][w];

        if (wt[n - 1] <= w)
            return dp[n][w] = max(val[n - 1] + knapSackHelper(w - wt[n - 1], wt, val, n - 1),
                                  knapSackHelper(w, wt, val, n - 1));
        else if (wt[n - 1] > w)
            return dp[n][w] = knapSackHelper(w, wt, val, n - 1);
    }

    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, int wt[], int val[], int n)
    {
        memset(dp, -1, sizeof(dp));
        return knapSackHelper(w, wt, val, n);
    }
};

// Tabulation - bottom up

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, int wt[], int val[], int n) { 
        int dp[1001][1001];
        memset(dp, 0, sizeof(dp));
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<w+1; j++){
                if(wt[i-1] <= j)
                    dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
                else 
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][w];
    }
};