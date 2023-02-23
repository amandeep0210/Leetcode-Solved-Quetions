class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n =grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0)), dis(n, vector<int>(m,0));
        queue<pair<int, int>> q;
        int R[] = {-1, 0, 1, 0};
        int C[] = {0, 1, 0, -1};
        for(int i= 0; i<n; i++){
            for(int j = 0; j< m; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        int dist = -1;
        while(q.size()){
            int s = q.size();
            for(int k = 0; k < s; k++){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            
            for(int i = 0; i<4; i++){
                int nr = r + R[i];
                int nc = c + C[i];
                if(nr >=0 and nr < n and nc >=0 and nc < m and vis[nr][nc] == 0 and grid[nr][nc] == 0){
                    vis[nr][nc] = 1;
                    grid[nr][nc] = 1 + grid[r][c];
                    dist = max(dist, grid[nr][nc]);
                    q.push({nr, nc});
                }
            }
            }
            
        }
        if(dist <= 0)return -1;
        return dist-1;
    }
};