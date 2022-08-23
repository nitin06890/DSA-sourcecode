// OJ: https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	int countZero(int arr[], int i){
	    int cnt = 0;
	    for(int j=0; j<=i; j++){
	        if(arr[j] == 0)
	            cnt++;
	    }
	    return cnt;
	}
	
	int perfectSum(int arr[], int n, int sum){
        long long dp[n+1][sum+1];
        long long mod = 1e9+7;
        
        for(int i=0, j=0; j<sum+1; j++)
            dp[i][j] = 0;
        for(int i=0, j=0; i<n+1; i++){
            dp[i][j] = pow(2, countZero(arr, i));
        }
        for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(arr[i-1] <= j)
                    dp[i][j] = ((dp[i-1][j-arr[i-1]])%mod + (dp[i-1][j])%mod)%mod;                                   
                else 
                    dp[i][j] = (dp[i-1][j])%mod;
            }
        }
        return dp[n][sum];
	}
	  
};