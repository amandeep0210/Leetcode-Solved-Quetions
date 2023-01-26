//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int mod = 1e9+7;
	    int fn(int ind, string str, vector<int>&dp){
	        if(ind == str.length())return 1;
	        if(ind > str.length())return 0;
	        if(dp[ind] != -1)return dp[ind];
	        
	        // try all the possible ways:
	        
	        int ans1 = 0, ans2 =0;
	        if(ind < str.length()){
	            int t = str[ind]-'0';
	            if(t == 0)ans1 =0;
	            else ans1 = fn(ind+1, str, dp);
	        }
	        
	        if(ind+1 < str.length()){
	            string temp = str.substr(ind, 2);
	            int t = stoi(temp);
	            if(t <= 26 and t>=10)ans2 = fn(ind+2, str, dp);
	            else ans2 = 0;
	        }
	        return dp[ind] = (ans1+ans2)%mod;
	    }
		int CountWays(string str){
		    // Code here
		    vector<int> dp(str.length()+1, -1);
		    return  fn(0, str, dp)%mod;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends