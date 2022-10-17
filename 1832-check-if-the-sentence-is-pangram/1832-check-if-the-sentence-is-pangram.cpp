class Solution {
public:
    bool checkIfPangram(string sentence) {
       unordered_map<int, int> mp; 
        for(auto it : sentence){
            mp[it-'a']++;
        }
        if(mp.size() == 26)return true;
        else return false;
    }
};