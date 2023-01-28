//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n = grid.size();
	    int m = grid[0].size();
	    vector<vector<int>> vis(n, vector<int>(m,0)), result(n, vector<int>(m,0));
	    queue<pair<pair<int, int>, int>> qp;
	    for(int i = 0; i<n; i++){
	        for(int j = 0; j<m; j++){
	            if(grid[i][j] == 1)qp.push({{i,j},0}), vis[i][j] = 1;
	        }
	    }
	    
	    int R[] = {-1, 0, 1, 0};
	    int C[] = {0, 1, 0, -1};
	    while(!qp.empty()){
	        int r = qp.front().first.first;
	        int c = qp.front().first.second;
	        int d = qp.front().second;
	        
	        result[r][c] = d;
	        qp.pop();
	        for(int i = 0; i<4; i++){
	            int nr = r + R[i];
	            int nc = c + C[i];
	            if(nr >=0 and nr < n and nc >=0 and nc < m and !vis[nr][nc]){
	                vis[nr][nc] = 1;
	                qp.push({{nr, nc},d+1});
	            }
	        }
	        
	    }
	    return result;
	   
	    
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends