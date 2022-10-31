class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i<m; i++){
            int r = 1;
            int c = i+1;
            while(r<n and c<m){
                if(matrix[r][c] != matrix[r-1][c-1]) return false;
                r++;
                c++;
            }
            
        }
        
        for(int i = 1; i<n; i++){
            int r = i+1;
            int c = 1;
            while(r<n and c <m){
                if(matrix[r][c] != matrix[r-1][c-1])return false;
                r++;
                c++;
            }
        }
        return true;
    }
};