class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> v;
        queue<int> q;
        int cnt = 0;
        vector<vector<int>>adj(n);
        vector<int> in(n, 0);
        for(int i = 0; i<pre.size(); i++){
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        
        for(int i = 0; i<n; i++){
            for(auto it : adj[i]){
                in[it]++;
            }
        }
        for(int i= 0; i<n; i++){
            if(!in[i])q.push(i);
        }
        while(q.size()){
            int node = q.front();
            cnt ++;
            v.push_back(node);
            q.pop();
            for(auto it :adj[node]){
                in[it]--;
                if(in[it] == 0)q.push(it);
            }
        }
        if(cnt == n)return v;
        return {};
    }
};