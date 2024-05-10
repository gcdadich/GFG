//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
   void recursion(int idx, vector<int> arr, int tempSum, int k, vector<int> temp, set<vector<int>> &s)
{
    if (tempSum == k)
    {
        s.insert(temp);
        return;
    }

    for (int i = idx; i < arr.size(); i++)
    {
        if (tempSum + arr[i] <= k)
        {
            temp.push_back(arr[i]);
            recursion(i + 1, arr, tempSum + arr[i], k, temp, s);
            temp.pop_back();
        }
        else // Avoiding unnecessary calls
        {
            break;
        }
    }
}

vector<vector<int>> CombinationSum2(vector<int> arr, int n, int k)
{
    sort(arr.begin(), arr.end());
    set<vector<int>> s;
    vector<int> temp;

    recursion(0, arr, 0, k, temp, s);
    vector<vector<int>> ans(s.begin(), s.end());

    return ans;
}

};

//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends