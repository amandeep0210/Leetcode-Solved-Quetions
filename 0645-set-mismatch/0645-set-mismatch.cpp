class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int a,b;
        int sum = 0;
        for(int i = 0; i<nums.size(); i++){
            sum += nums[i];
        }
        for(int i = 1; i<nums.size(); i++){
            if(nums[i] == nums[i-1]){
                a = nums[i];
            }
        }
        int n = nums.size();
        b = n*(n+1)/2 - sum + a;
        vector<int> v{a,b};
        return v;
    }
};