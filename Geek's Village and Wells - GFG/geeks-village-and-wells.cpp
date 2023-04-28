//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &grid){
       vector<vector<int>> result(n, vector<int>(m,0));
       queue<pair<int,int>> q;
       for(int i = 0; i< n; i++){
           for(int j = 0; j<m; j++){
               result[i][j] = (grid[i][j] == 'H' || grid[i][j] == '.') ? 1e9 : 0;
               if(grid[i][j] == 'W')q.push({i,j});
           }
       }
       int R[] = {-1, 0, 1, 0};
       int C[] = {0, 1, 0, -1};
       vector<vector<int>> vis(n, vector<int>(m, 0));
       while(!q.empty()){
          
               int r = q.front().first;
               int c = q.front().second;
               q.pop();
               for(int  k = 0; k< 4; k++){
                   int nr = r + R[k];
                   int nc = c + C[k];
                   if(nr >=0 and nr < n and nc >=0 and nc <m and (grid[nr][nc] == 'H' || grid[nr][nc] == '.')) {
                       int p =( (result[r][c]/2) + 1 )*2;
                       if(p < result[nr][nc]){
                       result[nr][nc] = min(p, result[nr][nc]);
                       q.push({nr, nc});  
                       }
                   }
                   
               }
       }
       for(int i = 0; i<n; i++){
           for(int j = 0; j<m ;j++){
               if(result[i][j] == 1e9)result[i][j] = -1;
               if(grid[i][j] == '.')result[i][j] = 0;
           }
       }
       return result;
       
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends