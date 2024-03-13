//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        Scanner sc=new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0){
            int n=sc.nextInt();
            int key=sc.nextInt();
            
            int[] arr = new int[n];
            for(int i=0;i<n;i++)
            {
                arr[i]=sc.nextInt();
            }
            
            Solution obj = new Solution();
            int res = obj.findElementAtIndex(n, key, arr);
            System.out.println(res);
            
        }
    }
}

// } Driver Code Ends


//User function Template for Java
class Solution {
    public static int findElementAtIndex(int n, int key, int[] arr) {
        
        // code here
        return arr[key];
    }
}