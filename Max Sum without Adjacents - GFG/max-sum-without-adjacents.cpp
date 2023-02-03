//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int fn(int ind, int &n, int *arr, vector<int> &dp){
	    if(ind < 0)return 0;
	    if(dp[ind] != -1)return dp[ind];
	    
	    // try all the possible ways :
	    int take = arr[ind] + fn(ind-2, n, arr, dp);
	    int notake = 0 + fn(ind-1, n, arr, dp);
	    return dp[ind] = max(take, notake);
	}
	int findMaxSum(int *arr, int n) {
	    vector<int> dp(n , -1);
	    return fn(n-1, n, arr, dp);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends