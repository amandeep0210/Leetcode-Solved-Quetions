//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int N, int M, int x, int y){    
       vector<vector<int>> vis(N, vector<int>(M,0)), mat(N, vector<int>(M,0));
      mat[x-1][y-1] = 1;
       queue<pair<int,int>> q;
       q.push({x-1,y-1});
       int R[] = {-1, 0, 1, 0};
       int C[] = {0, 1,  0, -1};
       int cnt = 0;
       while(!q.empty()){
           int s = q.size();
           bool f = false;
           for(int j = 0; j<s; j++){
           int r = q.front().first;
           int c = q.front().second;
           q.pop();
           vis[r][c] = 1;
           for(int i = 0; i< 4; i++){
               int nr = r + R[i];
               int nc = c + C[i];
               if(nr >=0 and nr < N and nc >=0 and nc < M and !vis[nr][nc] and mat[nr][nc] == 0) {
                    f = true;
                   mat[nr][nc] = 1;
                   q.push({nr, nc});
               }
           }
           
       }
       if(f)cnt++;
       }
       return cnt;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends