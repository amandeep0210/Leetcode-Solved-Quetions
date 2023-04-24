//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        vector<int> ans; 
        vector<int> pre, suff;
        stack<int> st;
        pre.push_back(-1);
        st.push(0);
        for(int i = 1; i<arr.size(); i++){
            while(st.size() and arr[st.top()] >= arr[i])st.pop();
            if(st.size())pre.push_back(st.top());
            else pre.push_back(-1);
            
            st.push(i);
        }
        while(st.size())st.pop();
        int n = arr.size();
        st.push(n-1);
        suff.push_back(-1);
        for(int i = n-2; i>=0; i--){
            while(st.size() and arr[st.top()] >= arr[i])st.pop();
            if(st.size())suff.push_back(st.top());
            else suff.push_back(-1);
            
            st.push(i);
        }
        reverse(suff.begin(), suff.end());
        // for(auto it : pre)cout << it << " " ;
        // cout <<endl;
        // for(auto it : suff)cout << it << " ";
        // cout << endl;
        for(int i = 0; i<n; i++){
            if(pre[i] == -1)ans.push_back(suff[i]);
            else if(suff[i] == -1)ans.push_back(pre[i]);
            else{
                int d1 = abs(i-pre[i]);
                int d2 = abs(i-suff[i]);
                if(d1 == d2){
                    if(arr[pre[i]] != arr[suff[i]]){
                    if(min(arr[pre[i]], arr[suff[i]]) == arr[pre[i]])ans.push_back(pre[i]);
                    else ans.push_back(suff[i]);
                    }
                    else{
                      if(min(d1, d2) == d1)ans.push_back(pre[i]);
                    else ans.push_back(suff[i]); 
                    }
                }
                else{
                    if(min(d1, d2) == d1)ans.push_back(pre[i]);
                    else ans.push_back(suff[i]);
                }
            }
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends