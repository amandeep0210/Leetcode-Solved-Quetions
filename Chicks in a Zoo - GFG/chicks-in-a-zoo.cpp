//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	long long int NoOfChicks(int n){
	    vector<long long int> v1, v2;
	    int j = 0;
	    v1.push_back(1);
	    v2.push_back(1);
	    for(int i =1; i<n;i++){
	        if(i-6>=0){
	            long long p = v1[i-1] - v2[j++];
	            v1.push_back(p + p*2);
	            v2.push_back(p*2);
	        }
	        else{
	            v1.push_back(v1[i-1] + v1[i-1]*2);
	            v2.push_back(v1[i-1]*2);
	        }
	    }
	    int n1 = v1.size();
	    return v1[n1-1];
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		long long int ans = obj.NoOfChicks(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends