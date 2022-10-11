//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          unordered_map<char, int> mp, mp2;
          vector<int> v;
          for(int  i =0; i<n; i++){
              mp[x[i]] = b[i];
              mp2[x[i]]++;
          }
          for(int i = 0;i<w.size(); i++ ){
              if(mp2[w[i]]){
                  v.push_back(mp[w[i]]);
              }
              else{
                  v.push_back(int(w[i]));
              }
          }
          
        long long sum = 0;
        long long max = INT_MIN;
        string s = "";
        string ans;
        for(int i = 0; i<w.size();i++){
            sum += v[i];
            s.push_back(w[i]);
            if(sum > max){
                max = sum;
                ans = s;
            }
            if(sum < 0){
               sum = 0;
               s = "";
            };
        }
        return ans;
      }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends