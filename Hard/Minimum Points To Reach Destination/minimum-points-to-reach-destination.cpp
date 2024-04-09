//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	
int help(int i, int j, vector<vector<int>> &points, int m, int n, vector<vector<int>> &dp)
{
    if (i == m - 1 && j == n - 1)
    {
        return (1 - points[i][j]);
    }
    if (i == m || j == n) // Out of bound situation
    {
        return INT_MAX;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int a = help(i + 1, j, points, m, n, dp);
    int b = help(i, j + 1, points, m, n, dp);

    return dp[i][j] = max(1, min(a, b) - points[i][j]);
}

int minPoints(int m, int n, vector<vector<int>> points)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return help(0, 0, points, m, n, dp);
}
};


//{ Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> a(m, vector<int>(n));

        for(int i = 0; i < m; i++)
        	for(int j = 0; j < n; j++)
        		cin >> a[i][j];

        

	    Solution ob;
	    cout << ob.minPoints(m,n,a) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends