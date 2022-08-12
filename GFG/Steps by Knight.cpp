// OJ: https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    struct cell
    {
        int x;
        int y;
        int steps;
    };

public:
    int minStepToReachTarget(vector<int> &kp, vector<int> &tp, int N)
    {
        kp[0]--;
        kp[1]--;
        tp[0]--;
        tp[1]--;

        vector<vector<bool>> vis(N, vector<bool>(N, false));
        vector<vector<int>> dxy = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
        queue<cell> q;

        q.push({kp[0], kp[1], 0});
        vis[kp[0]][kp[1]] = true;

        while (!q.empty())
        {
            int x = q.front().x;
            int y = q.front().y;
            int steps = q.front().steps;
            q.pop();

            if (x == tp[0] and y == tp[1])
                return steps;
            for (int i = 0; i < dxy.size(); i++)
            {
                int nx = x + dxy[i][0];
                int ny = y + dxy[i][1];
                if (nx >= 0 && ny >= 0 && nx < N && ny < N && vis[nx][ny] == false)
                {
                    q.push({nx, ny, steps + 1});
                    vis[nx][ny] = true;
                }
            }
        }
        return -1;
    }
};