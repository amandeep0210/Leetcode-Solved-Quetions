//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int mod = 1e9 + 7;
    int fn(int n, vector<int>&dp){
        if(n == 0 || n == 1)return 1;
        if(n < 0 )return 0;
        if(dp[n] != -1)return dp[n];
        int one = fn(n-1, dp);
        int two = ((n-1)*1LL*fn(n-2, dp))%mod;
        return dp[n] = (one+two)%mod;
    }
    int countFriendsPairings(int n) 
    {   vector<int> dp(n+1 , -1);
        return fn(n, dp)%mod;
    }
};    
 

//{ Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends