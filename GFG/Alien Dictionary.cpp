// OJ: https://practice.geeksforgeeks.org/problems/alien-dictionary/1

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string findOrder(string dict[], int n, int k)
    {
        vector<int> adj[k];
        vector<int> indegree(26, 0);
        for (int i = 0; i < n - 1; i++)
        {
            string s1 = dict[i];
            string s2 = dict[i + 1];
            int j = 0, k = 0;

            while (j < s1.size() and k < s2.size())
            {
                if (s1[j] != s2[k])
                {
                    adj[s1[j] - 'a'].push_back(s2[k] - 'a');
                    indegree[s2[k] - 'a']++;
                    break;
                }
                j++;
                k++;
            }
        }
        queue<int> q;
        for (int i = 0; i < k; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        string ans = "";
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (auto u : adj[v])
            {
                indegree[u]--;
                if (indegree[u] == 0)
                    q.push(u);
            }
            char ch = v + 'a';
            ans += ch;
        }
        return ans;
    }
};