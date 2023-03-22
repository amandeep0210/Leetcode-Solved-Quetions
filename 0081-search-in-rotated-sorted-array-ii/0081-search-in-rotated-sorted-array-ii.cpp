class Solution {
public:
    bool search(vector<int>& nums, int target) {
         int low = 0;
        int high = nums.size()-1;
        if(nums.size() == 1)return(nums[0]  == target);
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target)return  true;
            else if(nums[low] == nums[low] and nums[mid] == nums[low]){
                low++;
            }
            else if(nums[low] <= nums[mid]){
                if(target >= nums[low] and target < nums[mid]){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            else if(nums[mid] <= nums[high]){
                if(target > nums[mid] and target <= nums[high]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
        return false;
    }
};