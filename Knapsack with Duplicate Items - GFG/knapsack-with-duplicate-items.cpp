//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int fn(int ind, int w, int val[], int wt[], vector<vector<int>> &dp){
        if(ind == 0){
            return int(w/wt[ind])*val[ind];
          
        }
        if(dp[ind][w] != -1)return dp[ind][w];
        
        // try all the ways
        int notpick = fn(ind-1, w, val, wt, dp);
        int pick = INT_MIN;
        if(w>=wt[ind]){
            pick = val[ind] + fn(ind, w-wt[ind], val, wt, dp);
        }
        return dp[ind][w] = max(notpick, pick);
        
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N, vector<int> (W+1, -1));
       
        if(fn(N-1, W, val, wt, dp) <= INT_MIN)return 0;
         return fn(N-1, W, val, wt, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends