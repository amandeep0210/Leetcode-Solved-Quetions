//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
    bool isAnagram(char mp1[], char mp[]){
      for(int i = 0; i<26; i++){
        if(mp[i] != mp1[i])return false;
      }
      return true;
    }
	int search(string p, string s) {
	     int k = p.length();
        int i = 0;
        int j = 0;
        int ans = 0;
        char mp[26] = {0};
        for(auto it : p)mp[it-'a']++;
        char mpp[26] = {0};
        
        while(j < s.length()){
          mpp[s[j]-'a']++;
          if(j-i+1 < k)j++;
          else if(j-i+1 == k){
           if(isAnagram(mpp, mp)){
             ans++;
           }
           // slide the window : 
           mpp[s[i]-'a']--;
           i++;
           j++;
          }
        }
        return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends