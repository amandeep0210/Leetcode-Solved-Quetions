//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> satisfyEqn(int A[], int N) {
      unordered_map<int, pair<int, int>>mp;
      vector<vector<int>> vr;
      for(int i = 0; i<N; i++){
          for(int j = i+1; j<N; j++){
              int sum = A[i]+A[j];
              if(mp.find(sum) != mp.end()){
                    pair<int,int> &p = mp[sum];
                    if(i!=p.first && i!=p.second && j!=p.first && j!=p.second) vr.push_back({p.first,p.second,i,j});
              }
              else mp[sum] = {i,j};
          }
      }
      sort(vr.begin(),vr.end());
      if(vr.size() == 0){
          return  {-1,-1,-1,-1};
      }
      return vr[0];
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        vector<int> ptr = ob.satisfyEqn(A,N);
        
        cout<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3]<<endl;
    }
    return 0;
}
// } Driver Code Ends