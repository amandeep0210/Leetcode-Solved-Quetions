class Solution {
public:
    int solve(int idx,int curr,int const &t,vector<int> const &nums){
        if(idx == nums.size()){
            if(t == curr)
                return 1;
            return 0;
        }
        return (solve(idx+1,(curr | nums[idx]),t,nums) + solve(idx+1,curr,t,nums));
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int t = 0;
        // the maximum xor is the only xor result
        for(auto &x:nums)
            t |= x;
        return solve(0,0,t,nums);
    }
};