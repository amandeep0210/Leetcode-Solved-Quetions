class Solution {
public:
    void solve(vector<string> &result, string &ans, string &digits, int ind, unordered_map<int , string> &mp){
        if(ind == digits.length()){
            result.push_back(ans);
        }
        string cur = mp[digits[ind]- '0'];
        for(int i = 0; i<cur.length(); i++){
            ans.push_back(cur[i]);
            solve(result, ans, digits, ind+1, mp);
            ans.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
    unordered_map<int , string> mp;
    int a = 2,b= 3,c=4,d=5,e=6,f=7,g=8,h=9;
    mp[a] = "abc";
    mp[b] = "def";
    mp[c] = "ghi";
    mp[d] = "jkl";
    mp[e] = "mno";
    mp[f] = "pqrs";
    mp[g] = "tuv";
    mp[h] = "wxyz";
        vector<string> result;
        string ans = "";
        if(digits == "")return result;
        
        solve(result, ans, digits, 0, mp);
        return result;
    }
};