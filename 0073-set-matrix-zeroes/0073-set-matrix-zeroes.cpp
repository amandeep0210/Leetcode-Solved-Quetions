class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<pair<int,int>> vp;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == 0)vp.push_back({i,j});
            }
        }
        
        for(int i = 0; i <vp.size(); i++){
            int r = vp[i].first;
            int c = vp[i].second;
            for(int k = 0; k<n; k++){
                matrix[k][c] = 0;
            }
            for(int k = 0; k < m; k++){
                matrix[r][k] = 0;
            }
        }
        
    }
};