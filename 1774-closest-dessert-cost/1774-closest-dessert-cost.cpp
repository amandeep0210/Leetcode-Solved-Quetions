class Solution {
public:
    vector<int>result;
    void solve(int b, vector<int>&t, int ind){
        if(ind >= t.size()){
            result.push_back(b);
            return ;
        }
        for(int i = 0; i<=2; i++){
            b+= (i*t[ind]);
            solve(b, t, ind+1);
            b -= (i*t[ind]);
        }
    }
    int closestCost(vector<int>& b, vector<int>& t, int s) {
       for(int i = 0; i<b.size(); i++){
           solve(b[i],t , 0);
       } 
       int M = INT_MAX;
       int ans = INT_MAX;
        for(auto it : result){
            if(abs(it-s)<M){
                ans = it;
                M = abs(it-s);
            }
            else if(abs(it-s) == M){
                ans = min(ans, it);
            }
        }
        return ans;
    }
};