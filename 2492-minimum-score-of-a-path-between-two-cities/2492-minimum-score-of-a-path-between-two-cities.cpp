class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n+1];
        for(auto &v:roads){
            adj[v[0]].push_back({v[1],v[2]});
            adj[v[1]].push_back({v[0],v[2]});
        }
        int mini = INT_MAX;
        vector<int> vis(n+1,0);
        queue<int> q;
        q.push(1);
        vis[1]++;
        while(q.size()){
            int val = q.front();
            q.pop();
            for(auto &it:adj[val]){
                mini = min(mini, it.second);
                if(!vis[it.first]){
                    vis[it.first] = true;
                    q.push(it.first);
                }
            }
        }
        return mini;
    }
};