//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        vector<string> v;
        string sk = "";
        for(auto it : s){
            sk.push_back(it);
            v.push_back(sk);
        }
        vector<vector<string>> vs;
        for(int i = 0; i<v.size(); i++){
            set<string>st;
            for(int j = 0; j<n; j++){
                string check = contact[j].substr(0,v[i].length());
                if(check == v[i])st.insert(contact[j]);
            }
            vector<string> vr(st.begin(), st.end());
            if(vr.size() == 0)vr.push_back("0");
            vs.push_back(vr);
        }
        return vs;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends