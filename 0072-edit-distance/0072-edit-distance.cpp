class Solution {
public:
   // Memoize
    int solve(int i, int j, string &word1, string &word2, vector<vector<int>> &dp){
      if(i<0)return j+1;
      if(j<0)return i+1;
      // try all the possible ways
      if(dp[i][j] != -1)return dp[i][j];

      if(word1[i] == word2[j]) return dp[i][j] = 0 + solve(i-1,j-1,word1,word2,dp);
      int ins = 1 + solve(i,j-1,word1,word2,dp);// hypotheticaly insert ->become same move j
      int rep = 1 + solve(i-1,j-1,word1,word2,dp);// replace ->become same ->move i, j
      int del = 1 + solve(i-1,j,word1,word2,dp); // del ->move i ->check
      return dp[i][j] = min(ins, min(rep, del)); // min of all the operations
    }
    int minDistance(string word1, string word2) {
       vector<vector<int>>dp(word1.length()+1, vector<int>(word2.length()+1, 0));
      //  return solve(word1.size()-1, word2.size()-1, word1,word2,dp);


      // tabulation
      for(int i = 0; i<=word1.length();i++){
        for(int j = 0; j<=word2.size();j++){
          if(i == 0)dp[i][j] = j;
          else if(j == 0)dp[i][j] = i;
          else{
          if(word1[i-1] == word2[j-1])dp[i][j] = dp[i-1][j-1];
          else{
             dp[i][j] = min(1+dp[i-1][j-1], min(1+dp[i][j-1], 1+dp[i-1][j]));
          }
          }
        }
      }
      return dp[word1.length()][word2.length()]; 
    }
};