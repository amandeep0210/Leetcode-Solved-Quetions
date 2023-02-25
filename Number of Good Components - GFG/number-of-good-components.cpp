//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void dfs(int node, vector<vector<int>>&adj, vector<int> &vis){
      vis[node] = 1;
      for(auto it : adj[node]){
          if(!vis[it]){
              dfs(it, adj, vis);
          }
      }
  }
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        vector<int> v;
        vector<int> vis(V+1, 0);
        for(int i = 1; i<= V; i++){
            adj[i].push_back(i);
        }
        for(auto &it : adj){
            sort(it.begin(), it.end());
        }
        for(int i = 1; i <= V; i++){
            if(vis[i] == 0){
                v.push_back(i);
                dfs(i, adj, vis);
            }
        }
        int cnt = 0;
        for(int i = 0; i<v.size(); i++){
            bool f = true;
            
            vector<int> v1 = adj[v[i]];
            for(auto it  : adj[v[i]]){
                vector<int> v2 = adj[it];
                if(v2 != v1){
                    f = false;
                    break;
                }
            }
            if(f)cnt++;
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends