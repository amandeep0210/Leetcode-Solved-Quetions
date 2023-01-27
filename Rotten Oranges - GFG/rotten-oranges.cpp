//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int cnt = 0;
        queue<pair<pair<int, int>,int>>q;
        int n = grid.size();
        int m = grid[0].size();
        int vis[n][m];
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2){
                    vis[i][j] = 1;
                    q.push({{i,j},0});
                }
                else{
                    vis[i][j] = 0;
                }
                
                if(grid[i][j] == 1)cnt++;
            }
        }
        int R[] = {-1, 0, 1, 0};
        int C[] = { 0, 1, 0, -1};
        int ans = 0;
        int rott = 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            ans = max(ans, t);
            q.pop();
            for(int i = 0; i<4; i++){
               int nr = r + R[i];
               int nc = c + C[i];
                
                if(nr >= 0 and nr < n and nc >=0 and nc < m and !vis[nr][nc] and grid[nr][nc] == 1){
                    vis[nr][nc] = 1;
                    grid[nr][nc] = 2;
                    rott++;
                    q.push({{nr,nc},t+1});
                }
            }
            
        }
       if(rott != cnt)return -1;
       return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends