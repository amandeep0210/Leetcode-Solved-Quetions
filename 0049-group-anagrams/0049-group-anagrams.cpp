class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
       map<string, vector<string>> mp;
        for(int i = 0; i<strs.size(); i++){
            string k = strs[i];
            sort(k.begin(), k.end());
            mp[k].push_back(strs[i]);
        }
        vector<vector<string>> result;
        for(auto it : mp){
            result.push_back(it.second);
        }
        return result;  
    }
};