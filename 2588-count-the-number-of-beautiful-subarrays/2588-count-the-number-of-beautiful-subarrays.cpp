class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        vector<long long> pre;
        pre.push_back(nums[0]);
        for(int i = 1 ; i< nums.size(); i++){
            pre.push_back(pre[i-1]^nums[i]);
        }
        for(auto it : pre)cout << it << " ";
        cout << endl;
        unordered_map<long long, int> mp;
        mp[0] = 1;
        long long cnt = 0;
        for(int i = 0; i<pre.size(); i++){
            mp[pre[i]]++;
            if(mp[pre[i]]> 1)cnt += mp[pre[i]]-1;
        }
        // for(auto it : mp){
        //     cout << it.first << " " << it.second << endl;
        // }
        return cnt;
        
    }
};