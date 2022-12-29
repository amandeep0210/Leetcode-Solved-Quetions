//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool solve(int s, int &sum,int ind, int arr[], vector<vector<int>> &dp){
        if(ind == -1){
            return (sum - s == s);
        }
        // memoize :
         if(dp[ind][s] != -1)return dp[ind][s];
        // try the possible ways
        
        bool notpick = solve(s, sum, ind-1, arr, dp);
        bool pick = solve(s+arr[ind], sum, ind-1, arr, dp);
        return dp[ind][s] = (notpick || pick);
    }
    int equalPartition(int N, int arr[])
    {
        
        int sum =  accumulate(arr, arr+N, 0);
        vector<vector<int>> dp(N, vector<int>(sum+1, -1));
        int s = 0;
        return solve(s, sum, N-1, arr,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends