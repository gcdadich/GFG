//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            String[] str = br.readLine().trim().split(" ");
            int[] arr = new int[n - 1];
            for (int i = 0; i < n - 1; i++) {
                arr[i] = Integer.parseInt(str[i]);
            }
            Solution sln = new Solution();
            System.out.println(sln.missingNumber(n, arr));
        }
    }
}
// } Driver Code Ends


// User function Template for Java
class Solution {

    // Note that the size of the array is n-1
    int missingNumber(int n, int arr[]) {

             int x1 = 0;
        int x2 = 1;

        // For xor of all the elements in the array
        for (int i = 0; i < arr.length; i++) {
            x1 = x1 ^ arr[i];
        }

        // For xor of all the elements from 1 to n+1
        for (int i = 2; i < n + 1; i++) {
            x2 = x2 ^ i;
        }

        return (x1 ^ x2);
     }    
}
