class Solution {
public:
    vector<char> abc{'a','b','c'};
    vector<string> v;
    void solve(int ind, string &ans, int n){
        if(ind >= n){
            v.push_back(ans);
            return;
        }
        for(int i = 0; i<3; i++){
           if(ans.size() == 0){
               ans.push_back(abc[i]);
               solve(ind+1, ans, n);
               ans.pop_back();
           }
            else{
                if(ans[ans.size()-1] != abc[i]){
                ans.push_back(abc[i]);
                solve(ind+1, ans, n);
                ans.pop_back();
                }
            }
        }
    }
    string getHappyString(int n, int k) {
      
        string ans = "";
        solve(0, ans, n);
        if(v.size() < k)return "";
        return v[k-1];
        
    }
};