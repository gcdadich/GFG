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
            String result = ob.firstAlphabet(S);
            
            System.out.println(result);
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution {
    String firstAlphabet(String S) {
        // code here
        //// Split the string into words
        String []words = S.split("\\s+");
        // Initialize an empty string for first letters
        StringBuilder firstLetters = new StringBuilder();
        
        // Iterate over words and extract first letters
        for(String word : words){
            firstLetters.append(word.charAt(0));
        }
       
        return firstLetters.toString();
    }
};