class Solution {
public:
    int fn(int ind,vector<int> &nums, vector<int> &dp){
        if(ind < 0)return 0;
        if(dp[ind] != -1)return dp[ind];
        int rob = nums[ind] + fn(ind-2, nums, dp);
        int notrob = 0 + fn(ind-1, nums, dp);
        return dp[ind] = max(rob, notrob);
     
    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n, -1);
        return fn(n-1, nums, dp);
    }
};