//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
       priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int,int>>>q;
        vector<int> ways(n, 0);
        int mod = (int)(1e9 + 7);
        vector<pair<int,int>>adj[n];
        for(int i = 0; i<roads.size(); i++){
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        ways[0] = 1;
        vector<int>dist(n, 1e9);
        dist[0] = 0;
        q.push({0,0});
        while(!q.empty()){
            auto it = q.top();
            q.pop();
            int dis = it.first;
            int node = it.second;
            for(auto i : adj[node]){
                int nod = i.first;
                int d = i.second;
                if(d+dis < dist[nod]){
                    ways[nod] = ways[node];
                    dist[nod] = d+dis;
                    q.push({dist[nod],nod});
                }
                else if(d + dis == dist[nod]){
                    ways[nod] = (ways[nod] + ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends