class Solution {
public:
    long long fuel = 0;
    int dfs(int src, vector<int> &vis, vector<int> adj[], int &seats){
        int cnt = 1;
        vis[src] = 1;
        for(auto it : adj[src]){
            
            if(vis[it] == 0){
            cnt += dfs(it, vis, adj, seats);
            }
            
        }
        if(src != 0){
            fuel += (cnt/seats);
            if(cnt%seats)fuel++;
        }
        return cnt;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size()+1;
        vector<int> adj[n];
        vector<int>vis(n, 0);
        for(int i = 0; i< n-1; i++){
            adj[roads[i][0]].emplace_back(roads[i][1]);
            adj[roads[i][1]].emplace_back(roads[i][0]);
        }
        dfs(0, vis, adj, seats);
        return fuel;
        
    }
};