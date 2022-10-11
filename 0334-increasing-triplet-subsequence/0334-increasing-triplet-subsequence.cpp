class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int m1 = INT_MAX, m2 = INT_MAX;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]< m1){
                m1 = nums[i]; // got our first element 
            }
            if(m1 < nums[i] and nums[i]< m2){
                m2 = nums[i]; // got our 2nd element 
            }
            else if(m2 < nums[i]){
                return  true; // got our third element, no need to traverse more 
            }
        }
        return false;
    }
};