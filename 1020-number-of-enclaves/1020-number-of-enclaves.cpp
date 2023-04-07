class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        for(int i = 0; i< n; i++){
            for(int j = 0; j <m; j++){
                if(grid[i][j] == 1)cnt++;
                if((i == 0 || i == n-1 || j == 0 || j == m-1 )and grid[i][j] == 1)q.push({i,j});
            }
        }
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int R[] = {1, -1, 0, 0};
        int C[] = { 0, 0, 1, -1};
        int c1 = 0;
        while(q.size()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            if(vis[r][c] == 0){
            c1++;
            vis[r][c] = 1;
            
            for(int i = 0; i< 4; i++){
                int nr = r + R[i];
                int nc = c + C[i];
                if(nr >=0 and nr <= n-1 and nc >= 0 and nc <= m-1 and vis[nr][nc] == 0 and grid[nr][nc] == 1){
                    q.push({nr, nc});
                }
            }
            }
        }
        cout << cnt << " " << c1 << endl;
        return cnt - c1;
    }
};