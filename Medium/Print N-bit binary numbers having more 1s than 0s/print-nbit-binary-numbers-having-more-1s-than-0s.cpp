//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
void recursion(int n, vector<string> &ans, string temp)
{
    if (n == 0)
    {
        int cnt1 = 0;
        int cnt0 = 0;
        for (int i = 0; i < temp.size(); i++)
        {
            if (temp[i] == '1')
            {
                cnt1++;
            }
            else
            {
                cnt0++;
            }

            if (cnt0 > cnt1)
            {
                return;
            }
        }
        if (cnt1 >= (temp.size() / 2))
        {
            ans.push_back(temp);
        }
        return;
    }

    recursion(n - 1, ans, temp + '1');
    recursion(n - 1, ans, temp + '0');
}
	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	      vector<string> ans;
    recursion(n, ans, "");

    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends