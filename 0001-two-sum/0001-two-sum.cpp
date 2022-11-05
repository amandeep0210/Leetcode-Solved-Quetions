class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int , int> mp, mp2;
        for(auto i = 0; i<nums.size(); i++){
            mp[nums[i]] = i;
            mp2[nums[i]]++;
        }
        vector<int>result;
        for(int i = 0; i<nums.size(); i++){
            if(mp2[target - nums[i]] and mp[target - nums[i]] != i){
                result.push_back(i);
                result.push_back(mp[target-nums[i]]);
                break;
            }
        }
        return result;
    }
};