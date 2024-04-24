//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int ways(int x, int y)
{
    int mod = 1e9 + 7;
    if (x == 0 && y == 0)
    {
        return 1;
    }
    vector<vector<int>> dp(501, vector<int>(501, 0));

    for (int i = 0; i < 501; i++)
    {
        dp[0][i] = 1;
        dp[i][0] = 1;
        dp[i][1] = i + 1;
        dp[1][i] = i + 1;
    }

    for (int i = 2; i <= x; i++)
    {
        for (int j = 2; j <= y; j++)
        {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
        }
    }

    return dp[x][y];
}
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<<ob.ways(x,y)<<endl;
    }
	return 0;
}

// } Driver Code Ends