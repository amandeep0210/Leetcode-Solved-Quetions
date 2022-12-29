//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        stack<int> st;
        int i = 0; 
        while(i<N){
            if(st.size() == 0){
                st.push(asteroids[i++]);
            }
            else{
                int a = asteroids[i];
                if(st.top() > 0 and a>0){
                    st.push(a);
                    i++;
                }
                else if(st.top()<0 and a<0){
                    st.push(a);
                    i++;
                }
                else if(st.top()< 0 and a>0){
                    st.push(a);
                    i++;
                }
                else{
                    if(abs(st.top()) == abs(a)){
                        st.pop();
                        i++;
                    }
                    else if(abs(st.top()) > abs(a)){
                        i++;
                    }
                    else{
                        st.pop();
                    }
                }
            }
        }
        vector<int> result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends