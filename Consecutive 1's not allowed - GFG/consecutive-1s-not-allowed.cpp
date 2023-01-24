//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
    int mod = 1e9 + 7;
	#define ll long long
	ll fn(int n, vector<int>&dp){
	    if(n == 0)return 1;
	    if(n == 1)return 2;
	    if(n == 2)return 3;
	    if(dp[n] != -1)return dp[n]%mod;
	    // try all the possible ways :
	    ll a1 = fn(n-1 , dp)%mod;
	    ll a2 = fn(n-2, dp)%mod;
	    return dp[n] = (a1 + a2)%mod;
	}
	ll countStrings(int n) {
	    vector<int> dp(n+1, -1);
	    return fn(n, dp)%mod;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends