class Solution {
public:
  bool solve(int s, int&sum , int ind, vector<int> &nums, vector<vector<int>> &dp){
    
    if(ind == -1){
      return (sum - s  == s);
    }
    if(dp[ind][s] != -1)return dp[ind][s];
   
    bool notpick = solve(s, sum, ind-1, nums, dp);
    bool pick = solve(s+nums[ind], sum, ind-1, nums, dp);
    
    return dp[ind][s] = (notpick || pick);

  }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(),0);
        int s = 0;
        vector<vector<int>> dp(nums.size(), vector<int>(sum+1, -1));
        return solve(s, sum, nums.size()-1, nums,dp);

    }
};