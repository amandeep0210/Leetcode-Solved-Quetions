//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{

 

  public:

 int solve(int arr[], int n,int sum,int cur ,int indx,vector<vector<int>>&dp)  { 
     //base case 
     if (indx == n)
     return abs (sum-2*cur);
     if (dp[indx][cur]!=-1) return dp[indx][cur];
     int p = solve(arr,n,sum,cur+0,indx+1,dp);
     int q = solve (arr,n,sum,cur+arr[indx],indx+1,dp);
     return dp[indx][cur] = min(p,q);
 } 

 int minDifference(int arr[], int n)

 {
     int sum = 0;
     for (int i=0;i<n;i++)
     sum+=arr[i];
     vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
     return solve(arr,n,sum,0,0,dp);
 }

};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends