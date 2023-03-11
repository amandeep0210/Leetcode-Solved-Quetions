class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<int> vis(n+1, 0);
        for(int i = 0; i<n; i++){
            if(nums[i] > 0 and nums[i] <= n)vis[nums[i]]++;
        }
        for(int i = 1; i<= n; i++){
            if(vis[i] == 0)return i;
        }
        return n+1;
    }
};