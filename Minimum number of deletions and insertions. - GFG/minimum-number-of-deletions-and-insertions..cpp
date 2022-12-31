//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string str1, string str2) 
	{ 
        vector<vector<int>> dp(str1.size()+1, vector<int>(str2.size()+1, 0));
        for(int i = 0; i<=str1.size(); i++){
          for(int j = 0; j<=str2.size(); j++){
            if(i == 0 || j == 0)dp[i][j]= 0;
            else{
              if(str1[i-1] == str2[j-1])dp[i][j] = 1+dp[i-1][j-1];
              else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
          }
        }
        int lcs = dp[str1.size()][str2.size()];
        return str1.size() -lcs + str2.size() - lcs;
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends