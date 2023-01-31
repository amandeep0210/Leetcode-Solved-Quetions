class Solution {
public:
    int fn(int ind, int last, vector<pair<int, int>>&vp, vector<vector<int>> &dp){
        if(ind == -1)return 0;
        int n = vp.size(); 
        if(dp[ind][last] !=  -1)return dp[ind][last];
        // try all the possible ways:
        int pick = 0;
        int notpick = 0;
        if(last == n || vp[last].second >= vp[ind].second){
             pick = vp[ind].first + fn(ind-1, ind, vp, dp);
             notpick = 0 + fn(ind-1, last, vp, dp);
            
            return dp[ind][last] =  max(pick , notpick);
        }
        return dp[ind][last] = fn(ind-1, last, vp, dp);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int , int>> vp;
        for(int i = 0; i<scores.size(); i++){
          vp.push_back({scores[i], ages[i]});
        }
        sort(vp.begin(), vp.end());
        int n = vp.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return fn(n-1, n, vp, dp);

    }
};