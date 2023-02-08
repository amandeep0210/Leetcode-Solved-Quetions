class Solution {
public:
    long long int fn(int ind, vector<int>&nums, vector<int>&dp){
        if(ind >= nums.size()-1)return 0;
        if(dp[ind] != -1)return dp[ind];
        long long int mini = 1e9;
        for(int i = 1; i<=nums[ind];i++){
            mini = min(mini, 1 + fn(ind + i, nums,dp));
        }
        return dp[ind] = mini;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return fn(0, nums,dp);
    }
};