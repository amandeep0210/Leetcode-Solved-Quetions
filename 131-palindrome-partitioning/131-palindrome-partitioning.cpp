typedef vector<vector<string>> vvs;
typedef vector<string> vs;
class Solution {
public:
    bool paln(int ind, int i, string &s){
        while(ind <= i){
            if(s[ind] != s[i]){
                return false;
            }
            ind++;
            i--;
        }
        return true;
    }
    void solve(int ind, string &s, vs & ans, vvs & result){
        if(ind == s.length()){
            result.push_back(ans);
            return; 
        }
        for(int i = ind ; i<s.length(); i++){
            if(paln(ind, i, s)){
                ans.push_back(s.substr(ind, i-ind+1));
                solve(i+1,s, ans, result);
                ans.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        vvs result;
        vs ans;
        solve(0, s, ans, result);
        return result;
    }
    
};