class Solution {
public:
    unordered_map<string , int> mp;
    
    int solve(string s){
        int ans = 0;
        for(int i = 1; i<=s.length(); i++){
            string p = s.substr(0,i);
            if(!mp.count(p)){
                mp[p]++;
                ans = max(ans, 1+solve(s.substr(i)));
                mp[p]--;
                if(mp[p] == 0){
                mp.erase(p);
                }
            }
        }
        return ans;
    }
    int maxUniqueSplit(string s) {  
         return solve(s);
        // return ans;
    }
};