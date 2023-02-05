class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        queue<pair<int, pair<int, int>>> q;
        vector<int> dis(n, 1e9);
        dis[src] = 0;
        for(int i = 0;i < flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        q.push({0,{src,0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stp = it.first;
            int node = it.second.first;
            int d = it.second.second;
            if(stp > k)continue;
            for(auto i : adj[node]){
                if(d + i.second < dis[i.first] and stp <= k){
                    dis[i.first] = d + i.second;
                    q.push({stp+1, {i.first, dis[i.first]}});
                }
                
            }
        }
        if(dis[dst] == 1e9)return -1;
        return dis[dst];
    }
};