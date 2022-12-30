//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int fn(int ind, int price[], int n, vector<vector<int>>&dp){
        if(ind == 0){
            if(n % (ind+1) == 0)return (n/(ind+1)) * price[ind];
            return INT_MIN;
        }
        if(dp[ind][n] != -1)return dp[ind][n];
        
        // try all the possible ways ;
        int notpick = fn(ind-1, price, n, dp);
        int pick = INT_MIN;
        if(ind+1 <= n){
            pick = price[ind] + fn(ind, price, n-(ind+1), dp);
        }
        return dp[ind][n] = max(notpick, pick);
    }
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return fn(n-1, price, n, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends