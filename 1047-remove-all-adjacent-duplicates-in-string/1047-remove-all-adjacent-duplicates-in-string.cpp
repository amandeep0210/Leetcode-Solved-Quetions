class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        int i = 0;
        while(i<s.length()){
            if(st.size() == 0){
                st.push(s[i++]);
            }
            else{
                if(st.top() == s[i]){
                    st.pop();
                    i++;
                }
                else{
                    st.push(s[i++]);
                }
            }
        }
        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};