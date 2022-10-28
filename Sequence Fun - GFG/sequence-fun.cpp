//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
	public:
		int NthTerm(int n){
		    long long int k = 2;
		    long long int inc = 2;
		    for(int i = 1; i<n; i++){
		        k = (k*inc + 1) % 1000000007;
		        inc++;
		    }
		    return k % 1000000007;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution obj;
		int ans = obj.NthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends