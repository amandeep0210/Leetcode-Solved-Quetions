class Solution {
public:
    void fn(int ind, int target,vector<int>&temp, vector<vector<int>>&ans, vector<int>&nums){
        if(target < 0)return ;
        if(ind >= nums.size())return;
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        fn(ind,target-nums[ind],temp, ans, nums);
        temp.pop_back();
        fn(ind+1, target, temp, ans, nums);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        fn(0,target,temp, ans, candidates);
        return ans;
    }
};