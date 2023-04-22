class Solution {
public:
    int minInsertions(string s) {
      
        string s1 = s;
        reverse(s1.begin(), s1.end());
        vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1, 0));
        for(int i = 0; i<=s.size(); i++){
          for(int j = 0; j<=s.size(); j++){
            if(i == 0 || j == 0)dp[i][j]= 0;
            else{
              if(s[i-1] == s1[j-1])dp[i][j] = 1+dp[i-1][j-1];
              else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
          }
        }
        return s.length() - dp[s.size()][s.size()]; 
    }
};