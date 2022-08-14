// OJ: https://leetcode.com/problems/number-of-operations-to-make-network-connected/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(vector<int> adj[], vector<bool> &vis, int v)
    {
        vis[v] = true;
        for (auto u : adj[v])
        {
            if (!vis[u])
                dfs(adj, vis, u);
        }
    }

public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        if (connections.size() < n - 1)
            return -1;

        vector<int> adj[n];
        for (auto u : connections)
        {
            adj[u[0]].push_back(u[1]);
            adj[u[1]].push_back(u[0]);
        }

        vector<bool> vis(n, 0);
        int count_components = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(adj, vis, i);
                count_components++;
            }
        }
        return count_components - 1;
    }
};