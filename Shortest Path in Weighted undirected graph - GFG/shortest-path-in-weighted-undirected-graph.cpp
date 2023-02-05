//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
       vector<vector<int>> adj[n+1];
       for(int i = 0; i<m; i++){
           adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
           adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
       }
       priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
       q.push({0,1});
       vector<int> dis(n+1, 1e9);
       vector<int> res;
       dis[1] = 0;
       while(!q.empty()){
           int d = q.top().first;
            int no = q.top().second;
            q.pop();
            for(auto it : adj[no]){
                int node = it[0];
                int dist = it[1];
                if(dist + dis[no] < dis[node]){
                   dis[node] = dist+dis[no];
                   q.push({dis[node], node});
                }
            }
       }
       vector<int>v;
       queue<pair<int, int>> q1;
       q1.push({n, dis[n]});
       v.push_back(n);
       while(!q1.empty()){
           int curr = q1.front().first;
           int len = q1.front().second;
           if(curr == 1)break;
           q1.pop();
           bool f =  false;
           for(auto it : adj[curr]){
               int ad = it[0];
               int l  = it[1];
               if(len- l == dis[ad]){
                   f = true;
                   v.push_back(ad);
                   q1.push({ad, dis[ad]});
                   break;
               }
           }
           if(!f)return {-1};
       }
       reverse(v.begin(), v.end());
       return v;
          
           
       
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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