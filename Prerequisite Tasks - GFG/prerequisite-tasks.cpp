//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int>>& pre) {
	    vector<int> adj[N];
	    for(int i = 0; i<pre.size(); i++){
	        adj[pre[i].first].push_back(pre[i].second);
	    }
	    int ind[N] = {0};
	    for(int i = 0; i<N; i++){
	        for(auto it : adj[i])ind[it]++;
	    }
	    
	    queue<int> q;
	    int c = 0;
	    for(int i = 0; i<N; i++){
	        if(ind[i] == 0)q.push(i);
	    }
	    
	    while(!q.empty()){
	        int node = q.front();
	        c++;
	        q.pop();
	        for(auto it : adj[node]){
	            ind[it]--;
	            if(ind[it] == 0)q.push(it);
	        }
	    }
	    return (c == N);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends