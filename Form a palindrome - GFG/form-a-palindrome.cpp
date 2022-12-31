//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int findMinInsertions(string S){
        string s1 = S;
        reverse(s1.begin(), s1.end());
        // no we can treat as the lcs of s and s1;
        // that will be the longest palindrome;
        vector<vector<int>> dp(S.size()+1, vector<int>(S.size()+1, 0));
        for(int i = 0; i<=s1.size(); i++){
          for(int j = 0; j<=s1.size(); j++){
            if(i == 0 || j == 0)dp[i][j]= 0;
            else{
              if(S[i-1] == s1[j-1])dp[i][j] = 1+dp[i-1][j-1];
              else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
          }
        }
        return S.length()-dp[s1.size()][s1.size()];
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends