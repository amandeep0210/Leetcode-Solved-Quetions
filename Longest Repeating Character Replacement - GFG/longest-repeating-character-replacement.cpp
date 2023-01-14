//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int window(char c, string &s, int k){
      int a = 0;
      int j = 0;
      int  i = 0;
      while(j<s.length()){
        if(s[j] != c)k--;
        // if the char is not the required char , imagine to change it and decrease k
        while(k<0){
          if(s[i] != c){
            k++;
            i++;
          }
          else{
            i++;
          }
        }
        a = max(a, j-i+1);
        j++;
      }
      return a;
    }
    int characterReplacement(string s, int k) {
       unordered_map<char, int> mp;
        // check how many unique characters are there 
        for(auto it : s)mp[it]++; 
        int ans =INT_MIN;
        for(auto it : mp){
          // try to make the string with all its character as it
            ans = max(ans, window(it.first, s, k));
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;

        Solution obj;
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends