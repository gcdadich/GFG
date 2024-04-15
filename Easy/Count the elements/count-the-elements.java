//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;


class Array {
    
    // Driver code
	public static void main (String[] args) throws IOException{
		// Taking input using buffered reader
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int testcases = Integer.parseInt(br.readLine());
		// looping through all testcases
		while(testcases-- > 0){
		    int n=Integer.parseInt(br.readLine());
		    String line1 = br.readLine();
		    String line2 = br.readLine();
		    String[] a1 = line1.trim().split("\\s+");
		    String[] b1 = line2.trim().split("\\s+");
		    int a[]=new int[n];
		    int b[]=new int[n];
		    
		    for(int i=0;i<n;i++)
		    {
		        a[i]=Integer.parseInt(a1[i]);
		        b[i]=Integer.parseInt(b1[i]);
		    }
		    int q = Integer.parseInt(br.readLine());
		    int query[]=new int[q];
		    for(int i=0;i<q;i++)
		    {
		        query[i]=Integer.parseInt(br.readLine());
		    }
		    Solution ob=new Solution();
		    int ans[]=ob.countElements(a,b,n,query,q);
		    for(int i=0;i<q;i++)
		    System.out.println(ans[i]);
		    
		}
	}
}

// } Driver Code Ends


//User function Template for Java


class Solution
{
    public static int[] countElements(int a[], int b[], int n, int query[], int q)
    {
        int mx =-1;
        int ans[] = new int[q];
        for(int i=0;i<n;i++)mx=Math.max(mx,b[i]);
        int heap[] = new int[mx+1];
            Arrays.fill(heap,0);
            for(int i=0;i<n;i++) {heap[b[i]]++;}
            for(int i=1;i<=mx;i++){heap[i]+=heap[i-1];}
            for(int i=0;i<q;i++){
                if(a[query[i]]>mx){
                    ans[i]=n;
                }
                else ans[i] = heap[a[query[i]]];
            }
        
        return ans;
    }
}
