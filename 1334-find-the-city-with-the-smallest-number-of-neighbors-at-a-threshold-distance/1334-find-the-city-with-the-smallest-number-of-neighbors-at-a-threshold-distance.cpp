class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dis) {
       // using floyed warshal algo :
        vector<vector<int>> mat(n,vector<int>(n, 1e9));
        for(int i = 0; i<edges.size();i++){
            int s = edges[i][0];
            int e = edges[i][1];
            int wt = edges[i][2];
            mat[s][e] = wt;
            mat[e][s] = wt;   
        }
        
        for(int i = 0; i<n; i++)mat[i][i] = 0;
        for(int k = 0; k<n; k++){
            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    mat[i][j] = min(mat[i][j] , mat[i][k] + mat[k][j]);
                }
            }
        }
        
        int cnt = n;
        int city = -1;
        for(int i= 0; i<n; i++){
            int c = 0;
            for(int j = 0; j<n; j++){
                if(mat[i][j] <= dis){
                    c++;
                }
            }
            if(c <= cnt){
                cnt = c;
                city = i;
            }
        }
        return city;
    }
};