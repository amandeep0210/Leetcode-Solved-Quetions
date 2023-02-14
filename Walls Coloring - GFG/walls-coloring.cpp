//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int fn(int ind, int last, int N, vector<vector<int>> &colors, vector<vector<long long>> &dp){
        if(ind == N)return 0;
        if(dp[ind][last] != -1)return dp[ind][last];
        long long int a0 = 1e10, a1 = 1e10, a2 = 1e10;
        if(last == 0){
            a1 = colors[ind][1] + fn(ind+1, 1, N, colors, dp);
            a2 = colors[ind][2] + fn(ind+1, 2, N, colors, dp);
            return dp[ind][last] = min(a1, a2);
        }
        else if(last == 1){
            a0 = colors[ind][0] + fn(ind+1, 0, N, colors, dp);
            a2 = colors[ind][2] + fn(ind+1, 2, N, colors, dp);
            return dp[ind][last] = min(a0,a2);
        }
        else if(last == 2){
            a0 = colors[ind][0] + fn(ind+1, 0, N, colors, dp);
            a1 = colors[ind][1] + fn(ind+1, 1, N, colors, dp);
            return dp[ind][last] = min(a0,a1);
        }
        
    }
    int minCost(vector<vector<int>> &colors, int N) {
        auto it = colors[0];
        vector<vector<long long>> dp(N, vector<long long>(3, -1));
        return min(it[0] + fn(1,0,N, colors, dp), min(it[1] + fn(1,1, N, colors, dp), it[2] + fn(1, 2, N, colors, dp)));
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends