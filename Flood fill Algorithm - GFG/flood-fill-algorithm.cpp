//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
       vector<vector<int>> res;
       int vis[100][100] = {};
       int n = image.size();
       int m = image[0].size();
       int oldcolor = image[sr][sc];
       queue<pair<int, int>> q;
       q.push({sr, sc});
       image[sr][sc] = newColor;
       vis[sr][sc] = 1;
       while(!q.empty()){
           sr = q.front().first;
           sc = q.front().second;
           q.pop();
           if(sr+1 <n and image[sr+1][sc] == oldcolor and vis[sr+1][sc] == 0){
               vis[sr+1][sc] = 1;
               image[sr+1][sc] = newColor;
               q.push({sr+1, sc});
           }
           
           if(sr-1 >= 0 and image[sr-1][sc] == oldcolor and vis[sr-1][sc] == 0){
               vis[sr-1][sc] = 1;
               image[sr-1][sc] = newColor;
               q.push({sr-1, sc});
           }
           
           if(sc+1<m and image[sr][sc+1] == oldcolor and vis[sr][sc+1] == 0){
               vis[sr][sc+1] = 1;
               image[sr][sc+1] = newColor;
               q.push({sr, sc+1});
           }
           
           if(sc-1 >=0 and image[sr][sc-1] == oldcolor and vis[sr][sc-1] == 0){
               vis[sr][sc-1] = 1;
               image[sr][sc-1] = newColor;
               q.push({sr, sc-1});
           }
       }
       vector<vector<int>>ans(image.begin(), image.end());
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
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends