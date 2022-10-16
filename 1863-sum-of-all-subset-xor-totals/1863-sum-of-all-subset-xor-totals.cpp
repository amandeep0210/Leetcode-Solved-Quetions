class Solution {
public:
    int sum = 0;
int solve(int X, int ind, vector<int>& nums){
        if(ind == nums.size()){
            return X;
        }
        return solve((X ^ nums[ind]), ind+1, nums) + solve(X, ind+1, nums);
    }
    int subsetXORSum(vector<int>& nums) {
      return solve(0, 0, nums);
    }
};