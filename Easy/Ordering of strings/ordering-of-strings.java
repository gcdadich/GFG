//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;
class GfG
{
    public static void main(String args[])throws IOException
        {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            while(t-->0)
                {
                    int n = sc.nextInt();
                    String s[] = new String[n];
                    for(int i = 0;i<n;i++){
                        s[i] = sc.next();
                    }
                    
                    Solution ob = new Solution();
                    String ans[] = ob.orderString(s, n);
                    System.out.println(ans[0] + " " + ans[1]);
                }
        }
}
// } Driver Code Ends


//User function Template for Java

class Solution{
    String[] orderString(String s[], int n){
        Arrays.sort(s);
        String[] result = new String [2];
        result[0] = s[0];
        result[1] = s[n-1];
        return result;
    }
}