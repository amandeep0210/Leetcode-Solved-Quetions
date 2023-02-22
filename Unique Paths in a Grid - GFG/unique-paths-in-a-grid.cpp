//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int mod = 1e9 + 7;
    int solve(int r, int c, int n, int m, vector<vector<int>>&grid, vector<vector<int>>&dp){
        if(r == n-1 and c == m-1 and grid[r][c] != 0)return 1;
        if(r > n-1 || c > m-1)return 0;
        if(grid[r][c] == 0)return 0;
        if(dp[r][c] != -1)return dp[r][c];
        int path1 = 0, path2 = 0;
        path1 = solve(r, c+1, n, m, grid, dp);
        path2 = solve(r+1, c, n, m, grid, dp);
        return dp[r][c] = (path1 + path2)%mod;
        
        
    }
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0,0,n, m, grid, dp)%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends