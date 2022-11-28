class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> mp1, mp2;
        for(int i = 0 ; i< matches.size(); i++){
            mp1[matches[i][0]]++;
            mp2[matches[i][1]]++;
        }
        vector<vector<int>>result;
        vector<int>v1,v2;
        for(auto it : mp1){
            if(mp2[it.first] == 0)v1.push_back(it.first);
        }
        for(auto it : mp2){
            if(it.second == 1)
            v2.push_back(it.first);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        return {v1,v2};
    }
};