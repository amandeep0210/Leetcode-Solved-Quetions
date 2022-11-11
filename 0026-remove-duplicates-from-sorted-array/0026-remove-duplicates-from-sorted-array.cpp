class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        for(int i = 0;i<nums.size();i++){
            s.emplace(nums[i]);
        }
        nums.clear();
        for(auto it : s){
            nums.emplace_back(it);
        }
//         vector<int> v(s.begin(),s.end());
//         return v.size();
        return  nums.size();
        
    }
};