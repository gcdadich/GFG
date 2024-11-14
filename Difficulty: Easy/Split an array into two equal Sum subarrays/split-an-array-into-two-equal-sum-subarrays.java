//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String[] s = br.readLine().trim().split(" ");

            int[] arr = new int[s.length];
            for (int i = 0; i < arr.length; i++) arr[i] = Integer.parseInt(s[i]);

            Solution obj = new Solution();
            boolean res = obj.canSplit(arr);
            System.out.println(res);
        
System.out.println("~");
}
    }
}

// } Driver Code Ends




class Solution {
    public boolean canSplit(int arr[]) {
        // int leftsum = 0;
        // for (int i = 0; i < arr.length; i++) {
        //     leftsum += arr[i];

        //     int rightsum = 0;
        //     for (int j = i+1; j < arr.length; j++) {
        //         rightsum += arr[j];

        //         if (leftsum == rightsum) {
        //             return true;
        //         }
        //     }
        // }


        // return false;
        
        
         // code here
        int totalsum = 0;
        for (int i : arr) {
            totalsum += i;
        }
        if (totalsum % 2 != 0) {
            return false;  // odd total sum ,can't be split evenly
        }
        int targetsum = totalsum/2;
        int currsum = 0;
        for (int i : arr) {
           currsum += i;

           if (targetsum == currsum ) {
            return true;
           }else if (currsum > targetsum) {
            return false;
           }
        }

     return false;
    }
}