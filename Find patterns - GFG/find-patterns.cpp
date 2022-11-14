//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int numberOfSubsequences(string S, string W){
       int cnt = 0;
       int p = W.length();
       unordered_map<int, int> mp;
       for(int  i = 0; i<S.length(); i++){
           int k = 0;
           if(S[i] != W[0])continue;
           for(int j = i; j<S.length(); j++){
               
               if(S[j] == W[k] and mp[j] == 0){
                   k++;
                   mp[j] = 1;
               }
               if(k == p){
                   cnt++;
                   break;
               }
           }
       }
       return cnt;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends