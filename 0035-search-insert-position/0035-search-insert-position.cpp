class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (target<nums[0])return 0;
        int ans= -1, ind ;
        int s = 0;
        int e = nums.size()-1;
        while(s<=e){
            int m = s+ (e-s)/2;
            if(nums[m]<target){
                ind = m;
                s = m+1;
            }
            else if (nums[m]> target) {
                e= m-1;
            }
            else{
               ans = m;
                break;
            }
        }
        if (ans != -1)return ans;
        else return ind+1;
    }
};