class Solution {
public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int R[] = {0, 0, -1, 1};
        int C[] = {-1, 1, 0, 0};
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        queue<pair<int,int>> q;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                for(int k = 0; k<4; k++){
                    int nr = i + R[k];
                    int nc = j + C[k];
                    if(nr >=0 and nr < n and nc >= 0 and nc < m and mat[nr][nc] == 0 and vis[i][j] == 0 and mat[i][j] == 1){
                        vis[i][j] = 1;
                        q.push({i,j});
                    }
                }
            }
        }
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i<s; i++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int k = 0; k<4; k++){
                    int nr = r + R[k];
                    int nc = c + C[k];
                    if(nr >=0 and nr <n and nc>=0 and nc <m and !vis[nr][nc] and mat[nr][nc] == 1){
                        mat[nr][nc] = 1+mat[r][c];
                        vis[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
        return mat;
        
        
    }
};