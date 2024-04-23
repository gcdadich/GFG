//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int firstElement(int n)
{
    int mod = 1e9 + 7;

    if (n <= 2)
    {
        return 1;
    }

    int prev = 1;
    int prev2 = 1;
    for (int i = 3; i <= n; i++)
    {
        int curr = (prev + prev2) % mod;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends