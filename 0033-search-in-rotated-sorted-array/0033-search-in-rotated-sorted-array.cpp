class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target)return  mid;
            else if(low == high and target != nums[low])return -1;
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
        return -1;
    }
    
};