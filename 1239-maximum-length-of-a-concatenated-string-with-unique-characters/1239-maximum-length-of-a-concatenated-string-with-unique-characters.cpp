class Solution {
public:
    int ans = 0;
    bool check(string s) {
        set<char>st(s.begin(),s.end());
        if(st.size() == s.length())return true;
        else return false;
    }
    void f(int idx,string str, vector<string> &arr) {
        //backtrack solution here itself 
        if(!check(str)) {
            return;
        }
        if(str.length()>ans) {
            ans = str.length();
        }
        for(int i=idx;i<arr.size();i++) {
            string s = arr[i];
            f(i+1,str+s,arr);
        }
    }
    
    int maxLength(vector<string>& arr) {
        if(arr.size()==1) {
            if(check(arr[0])) {
                return arr[0].length();
            }
            return 0;
        }
        f(0,"",arr);
        return ans;
    }
};