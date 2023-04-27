//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string s) {
       int i = 0;
       int j = s.length()-1;
       int mp[26] = {0};
       for(auto it : s)mp[it-'a']++;
       bool f = true;
       unordered_map<int, int> mp1;
       while(i<=j){
           if(f == true){
               if(mp[s[i]-'a']>1){
                   mp[s[i]-'a']--;
                   mp1[i]++;
                   f = false;
               }
               i++;
               
           }
           else{
               if(mp[s[j]-'a']>1){
                   mp1[j]++;
                   mp[s[j]-'a']--;
                   f =  true;
               }
               j--;
           }
       }
    //   for(auto it : mp1)cout << it.first << " " ;
    //   cout << endl;
       string result = "";
       if(f == true){
          for(int i = 0; i<s.length(); i++){
              if(mp1[i]== 0)result.push_back(s[i]);
          } 
       }
       else{
          for(int i = s.length()-1; i>=0; i--){
              if(mp1[i]== 0)result.push_back(s[i]);
          } 
       }
       return result;
       
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends