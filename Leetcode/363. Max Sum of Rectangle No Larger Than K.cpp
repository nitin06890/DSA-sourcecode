// OJ: https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSumSubmatrix(vector<vector<int>> &mat, int k)
    {
        int row = mat.size(), col = mat[0].size();
        int res = INT_MIN;
        for (int l = 0; l < col; l++)
        {
            vector<int> sums(row, 0);
            for (int r = l; r < col; r++)
            {
                for (int i = 0; i < row; i++)
                {
                    sums[i] += mat[i][r];
                }
                set<int> st;
                st.insert(0);
                int curSum = 0, curMax = INT_MIN; // kadane algo
                for (int sum : sums)
                {
                    curSum += sum;
                    auto it = st.lower_bound(curSum - k);
                    if (it != st.end())
                        curMax = max(curMax, curSum - *it);
                    st.insert(curSum);
                }
                res = max(res, curMax);
            }
        }
        return res;
    }
};