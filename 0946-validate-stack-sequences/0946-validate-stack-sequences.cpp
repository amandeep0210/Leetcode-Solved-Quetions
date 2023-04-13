class Solution {
public:
    bool validateStackSequences(vector<int>& v1, vector<int>& v2) {
        stack<int> st;
        int j = 0;
        for(int i = 0; i<v1.size() and j < v2.size(); i++){
            st.push(v1[i]);
            while(st.size() and st.top() == v2[j]){
                st.pop();
                j++;
            }
        }
        if(st.size() == 0)return true;
        while(st.size() and j < v2.size()){
            if(st.top() == v2[j]){
                st.pop();
                j++;
            }
            else{
                return false;
            }
        }
        return true;
    }
};