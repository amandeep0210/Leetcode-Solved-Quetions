//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int fn(int s, int e, int arr[], vector<vector<int>>&dp){
        if(s == e)return 0;
        
        if(dp[s][e] != -1)return dp[s][e];
        // try all the possible ways :
        int mini = INT_MAX;
    
        for(int k = s; k<e; k++){
            int st = arr[s-1] * arr[k] * arr[e] + fn(s, k, arr, dp) + fn(k+1, e, arr, dp);
            mini = min(mini, st);
        }
        return dp[s][e] = mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
       vector<vector<int>> dp(N, vector<int>(N,-1));
       return fn(1, N-1, arr, dp);
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
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends