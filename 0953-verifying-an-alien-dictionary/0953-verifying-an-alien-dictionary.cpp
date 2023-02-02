class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int mp[26];
        for(int i = 0; i<26; i++){
            mp[order[i] - 'a'] = i;
        }
        for(auto &it : words){
            for(auto &x : it){
                x = mp[x-'a'];
            }
        }
        
        for(int i = 0; i< words.size()-1; i++){
            if(words[i+1] < words[i])return false;
        }
        return true;
    }
};