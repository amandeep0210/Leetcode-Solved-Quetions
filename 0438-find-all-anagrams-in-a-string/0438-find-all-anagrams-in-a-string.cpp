class Solution {
public:
    bool isAnagram(string &s1, char mp[]){
      char mp1[26] = {0};
      for(auto  it : s1)mp1[it -'a']++;
      for(int i = 0; i<26; i++){
        if(mp[i] != mp1[i])return false;
      }
      return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int k = p.length();
        int i = 0;
        int j = 0;
        char mp[26] = {0};
        for(auto it : p)mp[it-'a']++;
        string temp = "";
        vector<int> v;
        while(j < s.length()){
          temp.push_back(s[j]);
          if(temp.size() < k)j++;
          else if(temp.size() == k){
           if(isAnagram(temp, mp)){
             v.push_back(i);
           }
           // slide the window : 
           temp.erase(temp.begin()  + 0);
           i++;
           j++;
          }
        }
        return v;
    }
};