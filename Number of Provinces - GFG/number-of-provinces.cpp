//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
   void dfs(int k, vector<int> adj[], int vis[]){
       vis[k] = 1;
       for(auto it : adj[k]){
           if(!vis[it])dfs(it, adj, vis);
       }
   }
    int numProvinces(vector<vector<int>> adj, int V) {
      vector<int> ad[V];
      int vis[V] = {0};
      for(int i = 0; i<V; i++){
          for(int j = 0; j<V; j++){
              if(i!=j and adj[i][j] == 1){
                  ad[i].emplace_back(j);
                  ad[j].emplace_back(i);
                  
              }
          }
      }
      int cnt = 0;
      for(int i = 0; i<V; i++){
          if(!vis[i]){
              cnt++;
              dfs(i,ad, vis);
          }
      }
      return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends