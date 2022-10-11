class Solution {
public:
    int digits(int num){
        if(num == 0)return 1;
        return log10(num)+1;
        
    }
    void solve(int ind , int c, vector<string> & v, string & ans, string &s){
        if(ind >= s.length() and c == 4){
            // ans.pop_back();
            string res = ans.substr(0, ans.length()-1);
            v.push_back(res);
             return;
        }
        if(c == 4)return ;
        if(ind < s.length()){
            char k = s[ind];
            int n =  k- '0';
            ans.push_back(k);
            ans.push_back('.');
            solve(ind+1 , c+1 , v,ans, s);
            for(int i = 0; i<2; i++){
                ans.pop_back();
            }
        }
        if(ind+1< s.length()){
            string s2 =  s.substr(ind,2);
            int num =stoi(s2);
            if(digits(num) == 2){
                ans += s2;
                ans.push_back('.');
                solve(ind+2, c+1, v, ans, s);
                for(int i = 0; i<3; i++){
                    ans.pop_back();
                }
            }
        }
        
        if(ind+2< s.length()){
            string s3 = s.substr(ind,3);
            int num = stoi(s3);
            if(digits(num) == 3 and num<= 255){
                ans += s3;
                ans.push_back('.');
                solve(ind+3, c+1,v,ans, s);
                for(int i = 0; i<4; i++){
                    ans.pop_back();
                }
            }
        }
       
    }
    
    vector<string> restoreIpAddresses(string s) {
       vector<string> v;
        string ans = "";
        solve(0,0,v,ans, s);
        return v;
    }
};