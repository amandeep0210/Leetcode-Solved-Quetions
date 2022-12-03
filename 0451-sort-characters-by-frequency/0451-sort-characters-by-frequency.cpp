class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(auto it : s){
            mp[it]++;
        }
        vector<pair<int, char>> vp;
        for(auto it : mp){
            vp.push_back({it.second, it.first});
        }
        sort(vp.rbegin(), vp.rend());
        string ans  = "";
        for(int i = 0; i<vp.size(); i++){
            for(int j = 0; j<vp[i].first; j++){
                ans.push_back(vp[i].second);
            }
        }
        return ans;
    }
};