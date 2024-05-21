//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int findCrossOver(vector<int> &arr, int low, int high, int x)
{
    // Base cases
    if (arr[high] <= x)
    {
        return high;
    }
    if (arr[low] > x)
    {
        return low;
    }

    while (low <= high)
    {
        int mid = (low + high) / 2;

        // Check if mid is the crossover point
        if (arr[mid] <= x && arr[mid + 1] > x)
        {
            return mid;
        }
        // If x is greater than arr[mid], move to the right half
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        // If x is less than or equal to arr[mid], move to the left half
        else
        {
            high = mid - 1;
        }
    }

    // This return statement should never be reached due to the initial base cases.
    return low;
}

vector<int> printKClosest(vector<int> arr, int n, int k, int x)
{
    // move backward
    int id1 = findCrossOver(arr, 0, n - 1, x);

    // move forward
    int id2 = id1 + 1;

    // if element present then we have to neglect
    if (arr[id1] == x)
        id1--;

    vector<int> ans(k);
    for (int i = 0; i < k; i++)
    {
        // both pointing at valid index
        if (id1 >= 0 && id2 < n)
        {

            // int val1 = Math.abs(arr[id1]-x), val2 = Math.abs(arr[id2]-x);
            int val1 = x - arr[id1], val2 = arr[id2] - x;
            // val1 is more closet (diff small)
            if (val1 < val2)
            {
                ans[i] = arr[id1];
                id1--;
            }
            else
            {
                // val2 is more closet or if same we have to prioritize greater no
                ans[i] = arr[id2];
                id2++;
            }
        }
        else if (id1 >= 0)
        {
            ans[i] = arr[id1];
            id1--;
        }
        else
        {
            ans[i] = arr[id2];
            id2++;
        }
    }

    return ans;
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends