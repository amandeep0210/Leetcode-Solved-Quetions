//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{      
    public:
    bool static comp(pair<int, int> a, pair<int, int> b){
                return (a.second < b.second);
        }
        
        // dp : tle 
    // int fn(int ind, int last, vector<pair<int,int>> &vp, vector<vector<int>>&dp){
    //     if(ind < 0)return 0;
        
    //     if(dp[ind][last] != -1)return dp[ind][last];
        
    //     // try all the possible ways :
    //     bool f = true;
    //     if(vp[ind].first >= vp[last].first and vp[ind].first <= vp[last].second)f = false;
    //     if(last == vp.size() || f ==  true){
    //         int pick  = 1 + fn(ind-1, ind, vp, dp);
    //         int notpick = fn(ind-1,last, vp, dp);
    //         return dp[ind][last] =  max(pick, notpick);
    //     }
    //     return dp[ind][last] = fn(ind-1, last, vp, dp);
        
    // }
    
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int, int>> vp;
        int m = INT_MIN;
        for(int i = 0; i <n; i++){
            vp.push_back({start[i], end[i]});
        }
        sort(vp.begin(), vp.end(), comp);
        // dp : tle
        // reverse(vp.begin(), vp.end());
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // return fn(n-1, n, vp, dp);
        int c = 1;
        int e = vp[0].second;
        for(int i = 1; i<n; i++){
            if(vp[i].first > e){
                c++;
                e = vp[i].second;
            }
        }
        return c;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends