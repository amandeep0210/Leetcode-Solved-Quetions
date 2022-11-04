class Solution {
public:
    string reverseVowels(string s) {
        vector<char>v1;
        vector<int>v2;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u' or s[i] == 'A' or s[i] == 'E' or s[i] == 'I' or s[i] == 'O' or s[i] == 'U'){
            v1.push_back(s[i]);
            v2.push_back(i);
            
        }
        }
        reverse(v1.begin(), v1.end());
        for(int i = 0; i<v2.size();i++){
            s[v2[i]] = v1[i];
        }
        return s;
    }
};