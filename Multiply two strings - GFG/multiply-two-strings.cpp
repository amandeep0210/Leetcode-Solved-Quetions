//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
        if(s1 == "0" || s2 == "0")return "0";
        int n = 1e6;
        int k1 = 1;
        int k2 = 1;
       int ans[n] = {0};
       reverse(s1.begin(), s1.end());
       reverse(s2.begin(), s2.end());
       if(s1[s1.length()-1] == '-'){
           k1 = -1;
           s1.pop_back();
       }
       if(s2[s2.length()-1] == '-'){
           k2 = -1;
           s2.pop_back();
       }
       for(int i = 0; i<s2.size(); i++){
           int k = i;
           int rem = 0;
           for(int j = 0; j<s1.size(); j++){
               ans[k] += (s1[j] - '0') * (s2[i] - '0');
               ans[k] += rem;
               rem = ans[k]/10;//  update the rem
               ans[k] = ans[k] % 10;
               k++;
           }
           ans[k] += rem;
       }
       
       bool f = false;
    string s = "";
    for(long long i = 1e5-1; i>= 0; i--){
        if(ans[i]){
            f = true;
        }
        if(f){
            s.push_back(ans[i] + '0');
        }
    }
    if(k1*k2<0){
        s = "-" + s;
    }
    if(s.size() == 0)return "0";
    else return s;
    }
    

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends