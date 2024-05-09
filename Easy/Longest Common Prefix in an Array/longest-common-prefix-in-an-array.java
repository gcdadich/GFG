//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG
{
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0)
        {
            int n = Integer.parseInt(read.readLine().trim());
            String arr[] = read.readLine().trim().split(" ");

            Solution ob = new Solution();
            System.out.println(ob.longestCommonPrefix(arr, n));
        }
    }
}
// } Driver Code Ends




//User function Template for Java

class Solution{
    // String longestCommonPrefix(String arr[], int n){
        // code here
        // TreeMap<String,Integer> map = new TreeMap<>();
          
           
        //     for (int i = 0; i < n; i++) {
        //         String str = arr[i];
        //         String temp = "";
        //         for (int j = 0; j < str.length(); j++) {
        //             temp += str.charAt(j);
        //             map.put(temp, map.getOrDefault(temp,0)+1);
        //         }
        //     }
        //     String ans = "";
           
        //     for(Map.Entry<String,Integer>entry:map.entrySet()){
        //         if(entry.getValue()==n){
        //             if(entry.getKey().length()>ans.length()){
        //                 ans=entry.getKey();
        //             }
        //         }
        //     }
        //      if (ans.length() == 0) {
        //         return "-1";
        //     }
        //     return ans
        
    //}
    
    
    String longestCommonPrefix(String arr[], int n) {
        if (n == 0) return "-1";
        
        String prefix = arr[0];
        
        for (int i = 1; i < n; i++) {
            while (arr[i].indexOf(prefix) != 0) {
                prefix = prefix.substring(0, prefix.length() - 1);
                if (prefix.isEmpty()) return "-1";
            }
        }
        
        return prefix;
    }



}