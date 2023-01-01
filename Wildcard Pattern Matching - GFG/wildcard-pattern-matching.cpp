//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    int wildCard(string p,string s)
    {
        // tabulation : 
        int n = p.size();
        int m = s.size();
 
  vector < vector < bool >> dp(n + 1, vector < bool > (m+1, false));
  //  return fn(n,m,p,s,dp);

  // tabulation : 
  dp[0][0] = true;

  for (int j = 1; j <= m; j++) {
    dp[0][j] = false;
  }
  for (int i = 1; i <= n; i++) {
    bool f =  true;
    for(int k = 0; k<i; k++){
      if(p[k] != '*'){
        f =  false;
        break;
      }
    }
    dp[i][0] = f;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {

      if (p[i - 1] == s[j - 1] || p[i - 1] == '?')
        dp[i][j] = dp[i - 1][j - 1];

      else {
        if (p[i - 1] == '*')
          dp[i][j] = dp[i - 1][j] || dp[i][j - 1];

        else dp[i][j] = false;
      }
    }
  }

  return dp[n][m];
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends