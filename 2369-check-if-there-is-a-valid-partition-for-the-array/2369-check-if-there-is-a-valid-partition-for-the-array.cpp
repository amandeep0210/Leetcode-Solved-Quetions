class Solution {
public:
    bool fn(int ind, int &n, vector<int>&nums, vector<int>&dp){
        if(ind == n)return true;
        
        if(dp[ind] != -1)return dp[ind];
        // try all the possible ways;
        bool ans1 = false, ans2 = false, ans3 = false;
        
        if(ind+1 < n){
            if(nums[ind] == nums[ind+1]){
                ans1 = fn(ind+2, n, nums, dp);
            }
        }
        if(ind+2 < n){
            int cnt = 1;
            if(nums[ind+1] == nums[ind])cnt++;
            if(nums[ind+2] == nums[ind])cnt++;
            
            if(cnt == 3){
                ans2 = fn(ind+3, n, nums, dp);
            }
            
            cnt = 1;
            if(nums[ind+1] == 1+nums[ind])cnt++;
            if(nums[ind+2] == 1 + nums[ind+1])cnt++;
            if(cnt == 3){
                ans3 = fn(ind+3, n, nums, dp);
            }
        }
        return dp[ind] = (ans1 || ans2 || ans3);
    }
    bool validPartition(vector<int>& nums) {
        
        int n =  nums.size();
        vector<int> dp(n, -1);
        return fn(0, n, nums, dp);
    }
};