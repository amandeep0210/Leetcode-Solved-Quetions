class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans = 0;
        int i = 0;
        int j = nums.size()-1;
        while(i<=j){
            if(i == j){
                ans  += stoi(to_string(nums[i++]));
            }
            else{
                ans  += stoi(to_string(nums[i++]) + to_string(nums[j--])); 
            }
        }
        return ans;
    }
};