//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

    public:
    vector<vector<int> > findDistance(vector<vector<char> >& grid, int n, int m) 
    { 
       vector<vector<int>> result(n, vector<int>(m, -1));
       queue<pair<int,int>> q;
       for(int i = 0; i< n; i++){
           for(int j = 0; j<m; j++){
               if(grid[i][j] == 'B'){
                   q.push({i, j});
                   result[i][j] = 0;
               }
               else if(grid[i][j] == 'W'){
                   result[i][j] = -1;
               }
           }
       }
       int R[] = {-1, 0,1,0};
       int C[] = {0, 1,0, -1};
       int cnt = 0;
       while(!q.empty()){
           int s= q.size();
           bool f = false;
           for(int i = 0; i< s; i++){
               int r = q.front().first;
               int c = q.front().second;
               q.pop();
               for(int k = 0; k< 4; k++){
                   int nr  = r + R[k];
                   int nc = c + C[k];
                   if(nr >=0 and nc >= 0 and nr < n and nc < m and grid[nr][nc] == 'O'){
                       int inc = cnt+1;
                       grid[nr][nc] = 'B';
                       result[nr][nc] = inc;
                       q.push({nr, nc});
                       f =  true;
                   }
               }
           }
           if(f)cnt++;
       }
       
       for(int i = 0; i< n; i++){
           for(int j = 0; j< n; j++){
               if(result[i][j] == 1e9)result[i][j] = -1;
           }
       }
       return result;
    } 
};

//{ Driver Code Starts.


int main()
{

    int t;
    cin >> t;
    while(t--)
    {
    	int M,N;
        cin>>M;
        cin>>N;

        vector<vector<char> > matrix(M);
        for(int i=0; i<M; ++i)
        {
            matrix[i].resize(N);
            for (int j = 0; j < N; ++j)
                cin>>matrix[i][j];
        }

        vector<vector<int> >result;
        Solution obj;
        result = obj.findDistance(matrix, M,N); 
        for(int i=0; i<M; ++i)
        {
            for (int j = 0; j < N; ++j)
                cout<<result[i][j]<<" ";
            cout<<"\n";
        }
    }

    return 0;
}
// } Driver Code Ends