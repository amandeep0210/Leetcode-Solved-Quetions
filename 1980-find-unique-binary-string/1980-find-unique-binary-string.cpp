class Solution {
public:
    bool f = false;
    string result = "";
    void solve(vector<string> &nums, string &ans, map<string, int> &mp){
       if(ans.size() == nums.size()){
           if(mp[ans] == 0){
               result = ans;
               f =  true;
           }
           return ;
       }
        if(f ==  true)return;
        ans.push_back('0');
        solve(nums, ans, mp);
        ans.pop_back();
        ans.push_back('1');
        solve(nums, ans, mp);
        ans.pop_back();
    }
    string findDifferentBinaryString(vector<string>& nums) {
        map<string, int> mp;
        for(auto it : nums)mp[it]++;
        string ans = "";
        solve(nums, ans, mp);
        return result;
    }
};