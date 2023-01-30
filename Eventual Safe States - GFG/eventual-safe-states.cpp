//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   bool dfs(int node, int vis[], int path[], vector<int> adj[],  int check[]){
        vis[node] = 1;
        path[node] = 1;
        check[node] = 0;
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it,vis, path, adj, check)){check[node] = 0;return true;}
            }
            else{
                if(path[it] == 1){
                    check[node] = 0;
                    return true;
                }
            }
        
        }
        path[node] = 0;
        check[node] = 1;
        return false;
            
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        int vis[V] = {0};
        int path[V] = {0};
        int check[V] = {0};
        vector<int> ans;
        for(int i = 0; i<V; i++){
            dfs(i, vis, path, adj, check);
        }
        for(int i = 0; i<V; i++){
            if(check[i] == 1)ans.push_back(i);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends