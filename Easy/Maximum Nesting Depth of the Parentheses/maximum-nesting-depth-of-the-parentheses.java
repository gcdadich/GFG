//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        Scanner sc=new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0){
            sc.nextLine();
            String s;
            s = sc.next();
            
            Solution obj = new Solution();
            int res = obj.maxDepth(s);
            
            System.out.println(res);
            
        }
    }
}

// } Driver Code Ends


class Solution {
    public static int maxDepth(String s) {
        // code here
        int count = 0, prevCount=0;
        char []arr = s.toCharArray();
        Stack<Character> st = new Stack<>();
        for(char ch :arr){
            if(ch=='('){
                st.push('(');
                count++;
                prevCount = Math.max(count,prevCount);
            }else if(ch==')'){
                st.pop();
                count--;
            }
        }
        return prevCount;
    }
}
        
