//{ Driver Code Starts
/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;

class GFG {
	public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0){
            Solution obj = new Solution();
            System.out.println(obj.reverse(sc.next()));
        }
	}
}

// } Driver Code Ends


class Solution {
    
    public String reverse(String S){
        //code here
         char []arr = S.toCharArray();
        Stack<Character> st = new Stack<>();
        for(char ch :arr){
            st.push(ch);
        }
        for(int i=0;i<S.length();i++){
            arr[i]=st.pop();
        }
        return new String(arr);
    }

}