//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int N, string S, int X){
       vector<pair<int,int>> vp;
       for(int i = 0; i<N; i++){
           if(S[i] == '1'){
               vp.push_back({i-X, i+X});
           }
       }
    //   for(auto it : vp)cout << it.first << " " << it.second << endl;
       if(vp[0].first > 0)return false;
       if(vp[vp.size()-1].second < N-1)return false;
       
       for(int i = 1; i<vp.size(); i++){
           if(vp[i].first <= vp[i-1].second)continue;
           if(vp[i].first == vp[i-1].second+1)continue;
           if(vp[i].first > vp[i-1].second)return false;
       }
       return true;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends