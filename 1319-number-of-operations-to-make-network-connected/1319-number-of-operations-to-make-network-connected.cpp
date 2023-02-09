class DSU{
    
    public :
    vector<int> par, rank;
    DSU(int n){
        par.resize(n+1);
        rank.resize(n+1, 0);
        for(int i = 0; i<n; i++){
            par[i] = i;
        }
    }
        int findUltimateParent(int n){
            if(n == par[n])return n;
            return par[n] = findUltimateParent(par[n]);
        }
        void unionByRank(int u, int v){
            int Uv = findUltimateParent(v);
            int Uu = findUltimateParent(u);
            if(Uv == Uu)return;
            if(rank[Uu] < rank[Uv]){
                par[Uu] = Uv;
            }
            else if(rank[Uu] > rank[Uv]){
                par[Uv] = Uu;
            }
            else{
               par[Uv] = Uu;
               rank[Uu]++;
            }
            
        }
    
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& con) {
        vector<int> vis(n,0);
        DSU ds(n);
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0; i<con.size(); i++){
            int u = con[i][0];
            int v = con[i][1];
            vis[u]++;
            vis[v]++;
            int Upv = ds.findUltimateParent(v);
            int Upu = ds.findUltimateParent(u);
            if(Upv == Upu)cnt1++;
            else{
              ds.unionByRank(u,v);  
            }
            
            
        }
        for(int i = 0; i<n; i++){
            if(ds.par[i] == i)cnt2++;
        }
        if(cnt1>=cnt2-1)return cnt2-1;
        return -1;
    }
};