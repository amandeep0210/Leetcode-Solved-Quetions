class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        priority_queue<pair<long long , int>, vector<pair<long long , int>> , greater<pair<long long ,int>>>q;
        vector<long long > ways(n, 0);
        int mod = 1000000007;
        vector<pair<int,long long>>adj[n];
        for(int i = 0; i<roads.size(); i++){
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        ways[0] = 1;
        vector<long long >dist(n, 1e15);
        dist[0] = 0;
        q.push({0,0});
        while(!q.empty()){
            auto it = q.top();
            q.pop();
            long long  dis = it.first;
            int node = it.second;
            for(auto i : adj[node]){
                int nod = i.first;
                long long  d = i.second;
                if(d+dis < dist[nod]){
                    ways[nod] = ways[node]%mod;
                    dist[nod] = d+dis;
                    q.push({d+dis,nod});
                }
                else if(d + dis == dist[nod]){
                    ways[nod] = (ways[nod] + ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};