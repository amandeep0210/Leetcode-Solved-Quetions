class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        int i = 0; 
        while(i<s.length()){
            if(st.size() == 0){
                st.push(s[i++]);
            }
            else{
                 char k1 = tolower(s[i]);
                 char k2 = toupper(s[i]);
                if(st.top() != s[i] and (st.top() == k1 or st.top() == k2)){
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