//{ Driver Code Starts
import java.util.*;
import java.util.stream.*; 
import java.lang.*;
import java.io.*;

class GFG {
    
	public static void main (String[] args)throws IOException {
	
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		while(t-->0)
		{
		    String str = br.readLine();
		    String s1 = str.split(" ")[0];
		    String s2 = str.split(" ")[1];
		    
		    Solution obj = new Solution();
		    
		    if(obj.isAnagram(s1,s2))
		    {
		        System.out.println("YES");
		    }
		    else
		    {
		         System.out.println("NO");
		    }
		    
		    
		    
		}
	}
}
// } Driver Code Ends


class Solution
{    
    //Function is to check whether two strings are anagram of each other or not.
    public static boolean isAnagram(String a,String b)
    {
        
        // Your code here
         if(a.length()!=b.length()){
            return false;
        }
        char arrA[] = a.toCharArray();
        char arrB[] = b.toCharArray();
        Arrays.sort(arrA);
        Arrays.sort(arrB);
        int indexA = 0;
        int indexB = 0;
        int n = arrA.length;
        while(indexA<n && indexB<n){
            if(arrA[indexA]!=arrB[indexB]){
                return false;
            }
            indexA++;
            indexB++;
        }
        return true;
        /*
	 if (a.length()!=b.length()) {
            return false;
        }
        int n =a.length();
        int freq[] = new int[26];
        int indexA= 0;
        int indexB=0;
        while(indexA<n && indexB<n){
            char charA = a.charAt(indexA);
            //ascii value a =97
            int freqIndexA = charA-97;

            freq[freqIndexA]+=1;

            char charB = b.charAt(indexB);
            int freqIndexB = charB-97;

            freq[freqIndexB]-=1;
            indexA++;
            indexB++;
        }
        for (int i = 0; i < 26; i++) {
            if(freq[i] !=0){
                return false;
            }
        }
        return true;

	*/
    }
}
