class Solution {
public:
    int result = INT_MAX;
    void solve(int ind, vector<int>&ans, vector<int> &cookies){
        if(ind >= cookies.size()){
           int k = *max_element(ans.begin(), ans.end());
           result = min(result, k);
            return;
        }
        for(int i = 0; i<ans.size(); i++){
            ans[i] += cookies[ind];
            solve(ind+1, ans, cookies);
            ans[i] -=  cookies[ind];
        }
        
        
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> ans(k,0);
        solve(0, ans, cookies);
        return result;
    }
};