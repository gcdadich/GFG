//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;


// } Driver Code Ends
//User function Template for Java

class Solution
{
    //Function to perform case-specific sorting of strings.
    public static String caseSort(String str)
    {
        // Your code here
        StringBuilder lower = new StringBuilder();
        StringBuilder upper = new StringBuilder();
        for(int i=0;i<str.length();i++){
            char ch = str.charAt(i);
            if(ch>='a'&& ch<='z'){
                lower.append(ch);
            }else{upper.append(ch);}
        }
        //conver char array and sort char array -
        char lowerArray[] = lower.toString().toCharArray();
        char upperArray[] = upper.toString().toCharArray();
        Arrays.sort(lowerArray);
        Arrays.sort(upperArray);
        //make A StringBuilder for final sorting string contain
        StringBuilder ans = new StringBuilder();
        
        int lowerInd = 0;
        int upperInd = 0;
        
        for(int i=0;i<str.length();i++){
               char ch = str.charAt(i);
               if(ch>='a'&& ch<='z'){
                ans.append(lowerArray[lowerInd]);
                lowerInd++;
            }
            else{
                ans.append(upperArray[upperInd]);
                upperInd++;
                
            }
        }
        
        return ans.toString();
    }
}

//{ Driver Code Starts.

class GFG {
	public static void main (String[] args) {
		
    	try {
    	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	    PrintWriter out=new PrintWriter(System.out);
    	    String[] words = br.readLine().split("\\s+");
    	    int numTestCases = Integer.parseInt(words[0]);
    	    
    	    for (int tIdx = 0; tIdx < numTestCases; tIdx++) {
    	        words = br.readLine().split("\\s+");
    	        int size = Integer.parseInt(words[0]);
    	        String str = br.readLine();
    	        String sortedStr = new Solution().caseSort(str);
    	        out.println(sortedStr);
    	    }
    	    out.close();
    	}
    	catch (IOException e) {
    	    System.out.println(e);
    	}
	}
}
// } Driver Code Ends