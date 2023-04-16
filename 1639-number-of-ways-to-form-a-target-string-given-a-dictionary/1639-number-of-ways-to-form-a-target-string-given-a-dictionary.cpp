class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int t,int ind,vector<string>&words, string &target, vector<vector<int>>&dp){
        if(t == target.length()){
            return 1;
        }
        if(ind == words[0].size() || words[0].size()-ind < target.size()-t ){
            return 0;
        }
        if(dp[t][ind] != -1)return dp[t][ind];
        long long take = 0, notTake = 0;
        for(int i = 0; i<words.size(); i++){
        if(words[i][ind] == target[t]){
        take += solve(t+1, ind+1, words, target, dp)%mod;  
        }
        }
        notTake = solve(t, ind+1, words, target, dp)%mod;
        return dp[t][ind] =  (take + notTake)%mod;  
    }
    int numWays(vector<string>& words, string target) {
        vector<vector<int>> dp(1001, vector<int>(1001, -1));
        return solve(0, 0, words, target, dp);
    }
};