class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string ans = "";
        for(int i = 0; i<s.size(); i++){
            if(s[i] == ' '){
                if(ans != ""){
                st.push(ans);
                ans = "";
                }
            }
            else{
                ans.push_back(s[i]);
            }
        }
        if(ans != "")
        st.push(ans);
        string result = "";
        while(!st.empty()){
            result += st.top();
            st.pop();
            result.push_back(' ');
        }
        result.pop_back();
        return result;
    }
};