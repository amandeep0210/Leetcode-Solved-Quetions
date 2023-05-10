//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int N,int K,vector<int> &A){
        vector<int> pre(N), suff(N);
        pre[0] = A[0];
        suff[N-1] = A[N-1];
        for(int i = 1; i<N; i++){
            pre[i] = max(pre[i-1], A[i]);
        }
        for(int i = N-2; i>=0; i--){
            suff[i] = min(suff[i+1], A[i]);
        }
        int cnt = 0;
        for(int i = 1; i<N; i++){
            if(pre[i-1]+suff[i] >= K)cnt++;
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends