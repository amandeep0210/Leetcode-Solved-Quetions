typedef vector<vector<int>> vvi;
typedef vector<int> vv; 
class Solution {
public:
    void solve(vvi &result, vv &ans, int num, int n, int k){
    if(ans.size() == k){
    result.push_back(ans);
    return;
    }
    for(int i = num; i<= n; i++){
        ans.push_back(i);
        solve(result,ans, i+1, n, k);
        ans.pop_back();
        }    
    }
    
    vector<vector<int>> combine(int n, int k) {
        vvi result;
        vv ans;
        solve(result, ans,1, n, k);
        return result;
    }
};