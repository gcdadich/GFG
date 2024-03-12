//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String S = read.readLine();
            
            Solution ob = new Solution();
            System.out.println(ob.isPalindrome(S));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution {
    int isPalindrome(String S) {
        // code here
        //methods 1
        // int start = 0;
        // int end = S.length()-1;
        // while(start < end ){
        //     if(S.charAt(start) != S.charAt(end))
        //     return 0;
        // }
        // return 1;
        
        //methods 2
        //int start = 0;
        char arr[] = S.toCharArray();
        int n = arr.length;
        for(int i=0;i< n/2;i++){
            char start = arr[i];
            char end =arr[n-1-i];
            if(start != end){
                return 0;
            }
        }
            return 1;
        }
            
        }
        
        
    
