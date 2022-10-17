class Solution {
public:
    int ans = 0;
    bool isValid(string &p){
        string q = p;
        reverse(q.begin(), q.end());
        if(p == q)return true;
        else return false;
    }
    void solve(int ind , string  &s1, string & s2, string &s){
        if(ind  == s.length()){
            if(isValid(s1) and isValid(s2)){
                int l1 = s1.length();
                int l2 = s2.length();
                ans = max(ans, l1*l2);
            }
            return ;
        }
        s1.push_back(s[ind]);
        solve(ind+1, s1,s2,s);
        s1.pop_back();
        s2.push_back(s[ind]);
        solve(ind+1, s1,s2,s);
        s2.pop_back();
        solve(ind+1, s1,s2,s);
    }
    int maxProduct(string s) {
       string s1 = "", s2 = "";
       solve(0, s1, s2, s);
       return ans;
    }
};