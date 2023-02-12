class Solution {
public:
    int LOW(int s, int e, int val, vector<int>&nums, int& low ){
        int ind = 1e9;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(nums[mid] + val >= low){
                ind = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ind;
    }
    int UP(int s, int e, int val, vector<int>&nums, int &up){
        int ind = 1e9;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(nums[mid] + val <= up){
                ind = mid;
                s = mid+1;
            }
            else{
                e= mid-1;
            }
        }
        return ind;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        int n = nums.size();
        for(int i = 0; i<nums.size(); i++){
            int L = LOW(i+1, n-1, nums[i], nums, lower);
            if(L == 1e9)continue;
            int R = UP(L, n-1, nums[i], nums, upper);
            if(R == 1e9)continue;
            
            ans += R-L+1;
        }
        return ans;
    }
};