//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    long long solve(int X,int Y,string S){
      long long score = 0;
      stack<char> st;
      int i = 0;
      int sc = max(X,Y);
      string temp;
      if(max(X,Y) == X)temp = "pr";
      else temp = "rp";
      while(i<S.length()){
          if(st.size() == 0)st.push(S[i++]);
          else{
              if(st.top() == temp[0] and S[i] == temp[1]){
                  score += sc;
                  i++;
                  st.pop();
              }
              else{
                  st.push(S[i++]);
              }
          }
      }
      if(max(X,Y) == X)temp = "rp";
      else temp = "pr";
      string rem = "";
      while(st.size()){
          rem += st.top();
          st.pop();
      }
      reverse(rem.begin(), rem.end());
      sc = min(X,Y);
      i = 0;
      while(i < rem.length()){
          if(st.size() == 0)st.push(rem[i++]);
          else{
              if(st.top() == temp[0] and rem[i] == temp[1]){
                  st.pop();
                  score += sc;
                  i++;
              }
              else{
                  st.push(rem[i++]);
              }
          }
      }
      return score;
      
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends