class Solution {
public:
    string simplifyPath(string s) {
        stack<string> st;
        string t = "";
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '/'){
                if(t == ".." and st.size())st.pop();
                else if(t != "." and t != "" and t != "..")st.push(t);
                t = "";
            }
            else{
                t += s[i];
            }
        }
        if(t.size() and t == ".." and st.size())st.pop();
        else if(t.size() and t != "." and t!= "..")st.push(t);
        string ans = "";
        while(st.size()){
            ans  = '/' + st.top()+ans;
            st.pop();
        }
        if(ans.size() == 0)ans += '/';
        return ans;
    }
};