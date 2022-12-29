//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    long long fn(int r, int c, int &k, int sum, vector<vector<int>> &arr, int &n , vector<vector<vector<long long>>>&dp){
        if(sum > k)return 0;
        if(r>= n || c >= n)return 0;
        if(r == n-1 && c == n-1){
            if(sum + arr[n-1][n-1] == k)return 1;
            else return 0;
        }
        if(dp[r][c][sum] != -1)return dp[r][c][sum];
        long long right = fn(r , c+1, k, sum + arr[r][c], arr, n, dp);
        long long down = fn(r+1, c, k, sum + arr[r][c], arr, n, dp);
        if(sum > k)return 0;
        return dp[r][c][sum] =  right + down;
    }
    long long numberOfPath(int n, int k, vector<vector<int>> arr){
      vector<vector<vector<long long>>>dp(n, vector<vector<long long>>(n, vector<long long>(k+1, -1)));
        long long sum = 0;
        return fn(0, 0, k, sum, arr, n, dp);
    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n+1, vector<int>(n+1, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends