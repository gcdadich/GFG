//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
   int findShortestPath(vector<vector<int>> &matt)
{
    int n = matt.size();
    int m = matt[0].size();
    vector<vector<int>> mat = matt;
    vector<int> na{0, 0, -1, 1};
    vector<int> nb{1, -1, 0, 0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                int ni = i + na[k];
                int nj = j + nb[k];
                if (ni >= 0 && nj >= 0 && ni < n && nj < m && matt[ni][nj] == 0)
                {
                    mat[i][j] = 0;
                }
            }
        }
    }

    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < n; i++)
    {
        if (mat[i][0] == 1)
        {
            vis[i][0] = 1;
            q.push({{i, 0}, 1});
        }
    }

    int ans = INT_MAX;
    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dis = q.front().second;
        q.pop();

        if (y == m - 1) // means we are in the last column
        {
            ans = min(ans, dis);
        }

        for (int i = 0; i < 4; i++)
        {
            int newX = x + na[i];
            int newY = y + nb[i];

            if (newX >= 0 && newY >= 0 && newX < n && newY < m && vis[newX][newY] == 0 && mat[newX][newY] == 1)
            {
                q.push({{newX, newY}, dis + 1});
                vis[newX][newY] = 1;
            }
        }
    }

    if (ans == INT_MAX)
    {
        return -1;
    }
    return ans;
}

};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends