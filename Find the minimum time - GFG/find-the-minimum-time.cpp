//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPossible(int m, int S1, int S2, int n){
        int cnt = (m/S1 + m/S2);
        return (cnt >= n);
    }
    int minTime(int S1, int S2, int N){
        if(max(S1,S2)/min(S1,S2) >= N)return N*min(S1,S2);
      int l = 0;
      int r = N*max(S1, S2);
      while(r-l>1){
          int m = l + (r-l)/2;
          if(isPossible(m, S1, S2, N)){
              r = m;
          }
          else{
              l = m;
          }
      }
      return r;
      //3 5 2
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S1, S2, N;
        cin>>S1>>S2>>N;
        
        Solution ob;
        cout<<ob.minTime(S1, S2, N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends