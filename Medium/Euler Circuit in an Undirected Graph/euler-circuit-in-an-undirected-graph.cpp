//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
bool isEularCircuitExist(int n, vector<int>adj[]){
	    unordered_map<int,int> mp;
	    for(int i=0;i<n;i++)
	    {
	        if(adj[i].size()>=1)
	        mp[adj[i][0]]++;
	        
	        if(adj[i].size()>=2)
	        mp[adj[i][1]]++;
	    }
	    
	    for(auto it:mp)
	    {
	        if(it.second&1)
	        return 0;
	    }
	    
	    return 1;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isEularCircuitExist(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends