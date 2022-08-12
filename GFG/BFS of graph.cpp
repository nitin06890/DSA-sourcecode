// OJ: https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<bool> vis(V,false);
        queue<int> q;
        
        vis[0] = true;
        q.push(0);
        while(!q.empty()){
            int x = q.front();
            ans.push_back(x);
            q.pop();
            for(auto u : adj[x]) {
                if(vis[u] == true)
                    continue;
                vis[u] = true;
                q.push(u);
            }
        }
        return ans;
    }
};