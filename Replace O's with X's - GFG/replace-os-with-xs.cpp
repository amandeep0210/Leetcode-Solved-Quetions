//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    void dfs(int r, int c, vector<vector<char>> &mat, int vis[][500]){
        vis[r][c] = 1;
        int n = mat.size();
        int m = mat[0].size();
        int R[] = {0,1,0,-1};
        int C[] = {-1,0,1,0};
        for(int i = 0; i<4; i++){
            int nr = r+R[i];
            int nc = c+C[i];
            
            if(nr >=0 and nr < n and nc >=0 and nc < m and !vis[nr][nc] and mat[nr][nc] == 'O'){
                dfs(nr, nc, mat, vis);
            }
        }
        
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        int vis[500][500] = {0};
        
        // rows :
        for(int i = 0; i<m; i++){
            // first row :
            if(!vis[0][i] and mat[0][i] == 'O'){
                dfs(0, i, mat, vis);
            }
            // last row :
            if(!vis[n-1][i]  and mat[n-1][i] == 'O'){
                dfs(n-1, i, mat, vis);
            }
        }
        
        // col :
        for(int i = 0; i <n; i++){
            // first col :
            if(!vis[i][0] and mat[i][0] == 'O'){
                dfs(i, 0, mat, vis);
            }
            // last col :
            if(!vis[i][m-1]  and mat[i][m-1] == 'O'){
                dfs(i, m-1, mat, vis);
            }
        }
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m ; j++){
                if(vis[i][j] ==  0 and mat[i][j] == 'O'){
                    mat[i][j] = 'X';
                }
            }
        }
        vector<vector<char>> result(mat.begin(), mat.end());
        return result;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends