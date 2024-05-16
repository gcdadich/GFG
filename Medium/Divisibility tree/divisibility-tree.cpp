//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
	int dfs(vector<int> adj[], vector<int> &vis, int &ans, int node)
{
    vis[node] = 1;
    int size = 1;

    for (auto i : adj[node])
    {
        if (!vis[i])
        {
            int temp = dfs(adj, vis, ans, i);
            size += temp;
            if (temp % 2 == 0)
            {
                ans++;
            }
        }
    }

    return size;
}

int minimumEdgeRemove(int n, vector<vector<int>> edges)
{
    vector<int> adj[n + 1];

    for (auto i : edges)
    {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }

    vector<int> vis(n + 1, 0);
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(adj, vis, ans, i);
        }
    }

    return ans;
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>edges;
		for(int i = 0; i < n-1; i++){
			int x, y;
			cin >> x >> y;
			edges.push_back({x,y});
		}
		Solution obj;
		int ans = obj.minimumEdgeRemove(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}

// } Driver Code Ends