//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights)
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<int>> dist(rows, vector<int>(columns, INT_MAX));
    dist[0][0] = 0;
    pq.push({0, {0, 0}});

    int arrX[4] = {0, -1, 0, 1};
    int arrY[4] = {1, 0, -1, 0};

    while (!pq.empty())
    {
        int step = pq.top().first;
        int row = pq.top().second.first;
        int col = pq.top().second.second;
        pq.pop();

        if (row == rows - 1 && col == columns - 1)
        {
            return step;
        }

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + arrX[i];
            int ncol = col + arrY[i];

            if (nrow >= 0 && nrow < rows && ncol >= 0 && ncol < columns)
            {
                int val = max(step, abs(heights[nrow][ncol] - heights[row][col]));
                if (val < dist[nrow][ncol])
                {
                    dist[nrow][ncol] = val;
                    pq.push({val, {nrow, ncol}});
                }
            }
        }
    }

    return dist[rows - 1][columns - 1];
}
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}

// } Driver Code Ends