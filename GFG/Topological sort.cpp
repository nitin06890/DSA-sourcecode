// OJ: https://practice.geeksforgeeks.org/problems/topological-sort/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int> res;
        queue<int> q;
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++)
        {
            for (auto u : adj[i])
                indegree[u]++;
        }
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for (auto u : adj[node])
            {
                indegree[u]--;
                if (indegree[u] == 0)
                    q.push(u);
            }
        }
        return res;
    }
};