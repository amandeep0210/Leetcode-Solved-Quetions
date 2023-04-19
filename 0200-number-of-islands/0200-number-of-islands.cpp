class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid){
        int R[4] = {0, -1, 0, 1};
        int C[4] = {-1, 0, 1, 0};
        int n = grid.size();
        int m = grid[0].size();
        grid[i][j] = '2';
        for(int k = 0; k<4; k++){
            int r = i + R[k];
            int c = j + C[k];
            if(r >=0 and r <n and c>=0 and c <m and grid[r][c] == '1'){
                dfs(r, c, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    dfs(i, j, grid);
                }
            }
        }
        return cnt;
    }
};