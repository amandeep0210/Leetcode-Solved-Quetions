//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long  solve(int r, int c,vector<vector<int>> &Matrix, vector<vector<int>> &dp ){
        if(c<0 || c>=Matrix.size())return INT_MIN;
        if(r == Matrix.size()-1){
            return Matrix[r][c];
        }
        
        if(dp[r][c] != -1)return dp[r][c];
        
        // try all the possible ways 
        long long  down = Matrix[r][c] + solve(r+1, c, Matrix, dp);
        long long leftd = Matrix[r][c] + solve(r+1, c-1, Matrix, dp);
        long long rightd = Matrix[r][c] + solve(r+1, c+1, Matrix, dp);
        
        return dp[r][c] = max(down, max(leftd, rightd));
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
       vector<vector<int>> dp(N, vector<int>(N, -1));
       long long maxi = 0;
       for(int i = 0; i<N; i++){
           maxi = max(maxi, solve(0, i, Matrix, dp));
       }
       return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends