//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool bfs(int node , int color[], vector<int>adj[], int c){
        queue<pair<int, int>>q;
        q.push({node, c});
        while(!q.empty()){
            int n = q.front().first;
            int col =  q.front().second;
            q.pop();
            color[n] = col;
            for(auto it : adj[n]){
                if(color[it] == -1){
                   q.push({it, !col});
                }
                else{
                    if(color[it] == color[n])return false;
                }
            }
        }
        return true; 
    }
	bool isBipartite(int V, vector<int>adj[]){
	    int color[V] ;
	    for(int  i =0 ; i<V; i++){
	        color[i] = -1;
	    }
	   for(int i = 0; i<V; i++){
	       if(color[i] == -1){
	       if(bfs(i, color, adj, 0) ==  false)return false;
	       }
	   }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends