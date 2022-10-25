class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string ans1 = "";
        string ans2 = "";
        int i = 0; 
        int j = 0;
        while(i<word1.size() or j<word2.size()){
           if(i<word1.size()){
               ans1 += word1[i++];
           }
           if(j<word2.size()){
               ans2 += word2[j++];
           }
        }
        if(ans1 == ans2)return true;
        else return false;
    }
};