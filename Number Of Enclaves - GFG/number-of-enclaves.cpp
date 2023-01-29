//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   void dfs(int r, int c,vector<vector<int>> &grid, int vis[][500]){
       vis[r][c] = 1;
       int n = grid.size();
       int m = grid[0].size();
       int R[] = {-1, 0, 1, 0};
       int C[]  = {0, 1, 0, -1};
       for(int i = 0; i<4 ; i++){
          int nr = r +R[i];
          int nc = c + C[i];
          if(nr >=0 and nr < n and nc >=0 and nc <m and !vis[nr][nc] and grid[nr][nc] == 1){
              dfs(nr, nc, grid, vis);
          }
       }
   }
    int numberOfEnclaves(vector<vector<int>> &grid) {
       int n = grid.size();
       int m = grid[0].size();
       int vis[500][500]={0};
       
       // rows: 
       for(int i = 0; i<m; i++){
           if(!vis[0][i] and grid[0][i] == 1){
               dfs(0, i, grid, vis);
           }
           
           if(!vis[n-1][i] and grid[n-1][i] == 1){
               dfs(n-1, i, grid, vis);
           }
       }
       
       
       // cols :
       for(int i = 0; i<n; i++){
           if(!vis[i][0] and grid[i][0] == 1){
               
               dfs(i, 0, grid, vis);
           }
           
           if(!vis[i][m-1] and grid[i][m-1] == 1){
               dfs(i,m-1, grid, vis);
           }
           
       }
       
       int cnt = 0;
       for(int i = 0; i<n; i++){
           for(int j = 0; j<m; j++){
               if(vis[i][j] == 0 and grid[i][j] == 1)cnt++;
               
           }
       }
       return cnt;
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
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends