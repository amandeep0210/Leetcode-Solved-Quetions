class Solution {
public:
    int solve(int ind,int k,vector<vector<int>>& piles,vector<vector<int>> &dp){
        if(k == 0 || ind == piles.size())return 0;
        if(dp[ind][k] != -1)return  dp[ind][k];
        int sum = 0;
        int maxi = solve(ind+1, k, piles, dp);
         int t = k;
        for(int i = 0; i<piles[ind].size() and i < t ; i++){
           sum += piles[ind][i];
           k--;
           maxi = max(maxi, sum + solve(ind+1, k, piles, dp));
        }   
        return dp[ind][t] = maxi;   
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>> dp(piles.size()+1, vector<int>(k+1, -1));
        return solve(0, k, piles, dp);
    }
};