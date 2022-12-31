//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int fn(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
      // base case : when the index goes to negative then the lcs will of  length 0
      if(i <0 || j<0)return 0;
      if(dp[i][j] != -1)return dp[i][j];

      // try all the possible ways :
      // if the charcater mathces on a i and j then we can find for  rest of the strings
      if(s1[i] == s2[j]){
       return dp[i][j] = 1 + fn(i-1, j-1, s1,s2,dp);
      }
      // other wise there will be two calls 
     // once call move i to i-1 and then move j to j-1 and find the max of both

     return dp[i][j] = max(fn(i-1, j,s1,s2,dp), fn(i, j-1,s1,s2,dp));
    }
    int lcs(int x, int y, string s1, string s2)
    {
        vector<vector<int>> dp(x, vector<int>(y, -1));
        return fn(x-1, y-1, s1, s2, dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends