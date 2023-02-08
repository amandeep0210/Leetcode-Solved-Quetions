//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,int dis) {
        vector<vector<int>>mat(n, vector<int> (n,INT_MAX));
        for(int i = 0; i<edges.size(); i++){
            int s = edges[i][0];
            int d =  edges[i][1];
            int wt = edges[i][2];
            mat[s][d] = wt;
            mat[d][s] = wt;
        }
        
        for(int i = 0; i<n; i++)mat[i][i] = 0;
        int ans = -1;
        for(int k = 0; k < n; k++){
            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    if(mat[i][k] == INT_MAX || mat[k][j] == INT_MAX)continue;
                    mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j]);
                }
            }
        }
        int cnt = n;
        int number = -1;
        for(int i = 0; i<n; i++){
            int c = 0;
            for(int j = 0; j < n; j++){
                if(mat[i][j] <= dis)c++;
            }
            if(c <= cnt){
                cnt = c;
                number = i;
            }
            
        }
        return number;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends