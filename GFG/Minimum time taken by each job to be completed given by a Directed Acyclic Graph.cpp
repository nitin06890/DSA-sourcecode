// OJ: https://practice.geeksforgeeks.org/problems/minimum-time-taken-by-each-job-to-be-completed-given-by-a-directed-acyclic-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> minimumTime(int n, vector<vector<int>> &edges, int m)
    {
        vector<int> indegree(n + 1, 0);
        vector<int> adj[n + 1];
        for (auto u : edges)
        {
            indegree[u[1]]++;
            adj[u[0]].push_back(u[1]);
        }

        vector<int> ans(n + 1);
        queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
                ans[i] = 1;
            }
        }
        int count = 0;
        while (!q.empty())
        {
            auto v = q.front();
            q.pop();
            for (auto u : adj[v])
            {
                indegree[u]--;
                if (indegree[u] == 0)
                {
                    q.push(u);
                    ans[u] = ans[v] + 1;
                }
            }
        }
        ans.erase(ans.begin());
        return ans;
    }
};