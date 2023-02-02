//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  void dfs(int node, int vis[], vector<pair<int, int>> adj[], stack<int> &st){
      vis[node] = 1;
      for(auto it : adj[node]){
          if(!vis[it.first]){
              dfs(it.first, vis, adj, st);
          }
      }
      // topo sort :
      st.push(node);
  }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
         
         // make an adjacency list :
        vector<pair<int,int>> adj[N];
        for(int i = 0; i<M; i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        
        // do the topo sort using plan dfs;
        stack<int>st;
        int vis[N] = {0};
        for(int i =0 ; i<N; i++){
            if(!vis[i]){
                dfs(i, vis, adj, st);
            }
        }
        
        // make a distance array :
        vector<int> dis(N, 1e9);
        dis[0] = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            for(auto it : adj[node]){
                int mini = min(dis[it.first], dis[node] + it.second);
                dis[it.first] = mini;
            }
        }
        for(int i = 0; i<N; i++){
            if(dis[i] == 1e9)dis[i] = -1;
        }
        return dis;
        
    }
};
// 0 2 -1 8 10

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends