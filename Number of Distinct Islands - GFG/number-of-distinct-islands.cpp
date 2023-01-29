//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int r, int c, int vis[][500],vector<vector<int>>& grid, int br, int bc, vector<pair<int, int>>&vp){
        vis[r][c] = 1;
        vp.push_back({r-br, c-bc});
        int n = grid.size();
        int m = grid[0].size();
        int R[] = {-1,0,1,0};
        int C[] = {0,1,0,-1};
        for(int i = 0; i<4; i++){
            int nr =R[i] + r;
            int nc = C[i] + c;
            if(nr >= 0 and nr < n and nc >=0 and nc < m and !vis[nr][nc]  and grid[nr][nc] == 1){
                dfs(nr,nc, vis, grid, br,bc, vp);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int vis[500][500] = {0};
        // dfs;
        set<vector<pair<int, int>>> p;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                vector<pair<int,int>> vp;
                if(!vis[i][j] and grid[i][j] == 1){
                    dfs(i, j, vis, grid, i, j , vp);
                    p.insert(vp);
                }
                
            }
            
        }
        return p.size();
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends