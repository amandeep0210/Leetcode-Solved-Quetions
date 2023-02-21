class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        int n = nums.size();
        if(n == 1)return nums[0];
        int ind;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(mid == 0 and nums[1] != nums[0])return nums[0];
            if(mid == n-1 and nums[n-1] != nums[n-2])return nums[n-1];
            if(nums[mid] == nums[mid-1]){
               int i = mid;
               if(mid%2){
                   s = mid+1;
               }
               else{
                   e = mid-1;
               }
            }
            else if(nums[mid] == nums[mid+1]){
                int i = n-mid+1;
                if(i%2){
                    e = mid-1;
                }
                else{
                    s = mid+1;
                }
            }
            else{
                ind = mid;
                break;
            }
        }
        return nums[ind];
    }
};