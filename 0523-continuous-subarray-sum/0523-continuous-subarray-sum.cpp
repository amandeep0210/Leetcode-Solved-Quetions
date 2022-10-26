class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
		int sum = 0;
        unordered_map<int, int> m;
        m[0]=-1;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            int mod = k == 0 ? sum : sum % k;
			
            if (!m.count(mod)) m[mod]=i;
			
            if (m.count(mod)&&i-m[mod]>1) return true;
        }
        return false;
    }
};