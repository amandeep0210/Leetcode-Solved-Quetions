class Solution {
public:
    bool isPossible(vector<long long> nums, int m){
        int n = nums.size();
        for(int i = n-1; i>=1; i--){
            if(nums[i] <= m)continue;
            else{
                long long inc = abs(m-nums[i]);
                nums[i] = m;
                nums[i-1] += inc;
            }
        }
        int maxi = *max_element(nums.begin(), nums.end());
        return (maxi == m);
    }
    int minimizeArrayValue(vector<int>& nums) {
        int s = 1;
        int e = *max_element(nums.begin(), nums.end()) ;
        vector<long long> v(nums.begin(), nums.end());
        while(e-s>1){
            int m = s + (e-s)/2;
            if(isPossible(v,m))e = m;
            else s = m;
        }
        return e;
    }
};