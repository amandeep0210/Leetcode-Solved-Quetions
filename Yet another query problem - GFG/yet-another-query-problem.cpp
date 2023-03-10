//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> solveQueries(int N, int num, vector<int> &arr, vector<vector<int>> &Q) {
        vector<int> pre(N);
        unordered_map<int,int> mp;
        for(int i = N-1; i>=0; i--){
            mp[arr[i]]++;
            pre[i] = mp[arr[i]];
        }
        vector<int> result;
        for(int i = 0; i< Q.size(); i++){
            int L = Q[i][0];
            int R = Q[i][1];
            int k = Q[i][2];
            int cnt = 0;
            for(int i = L; i<=R; i++){
                if(pre[i] == k)cnt++;
            }
            result.push_back(cnt);
        }
        return result;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int num;
        cin>>num;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0;i<num;i++){
            for(int j=0;j<3;j++){
                cin>>Q[i][j];
            }
        }
        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends