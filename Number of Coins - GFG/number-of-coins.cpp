//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	long long  fn(int ind, int V, int coins[], vector<vector<long long>>&dp){
	    if(ind == 0){
	        if(V % coins[0] == 0)return V/coins[0];
	        return INT_MAX;
	    }

	    if(dp[ind][V]!= -1)return dp[ind][V];
	    // try all the possible way :
	    
	    long long notpick = fn(ind-1, V, coins, dp);
	    long long pick = INT_MAX;
	    if(coins[ind] <= V){
	        pick = 1 + fn(ind, V-coins[ind], coins,dp);// i am standing on the same ind so that i can pick it again.
	    }
	    return dp[ind][V] = min(notpick, pick);
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    vector<vector<long long>> dp(M, vector<long long>(V+1, -1));
	    if(fn(M-1, V, coins, dp) >= INT_MAX)return -1;
	    else return fn(M-1, V, coins, dp);
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends