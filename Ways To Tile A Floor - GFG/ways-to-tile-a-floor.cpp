//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int mod = 1e9+7;
    long long fn(long long n, vector<long long> &dp){
        if(n <= 1)return 1;
        if(dp[n] != -1)return dp[n]%mod;
        
        return dp[n] = (fn(n-2, dp)%mod + fn(n-1, dp)%mod)%mod;
    }
    long long numberOfWays(long long N) {
       vector<long long > dp(N+1, -1);
       return fn(N, dp)%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.numberOfWays(N) << endl;
    }
    return 0;
}
// } Driver Code Ends