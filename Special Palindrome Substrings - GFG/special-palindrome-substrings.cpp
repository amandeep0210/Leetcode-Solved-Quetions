//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
    //Complete the function and return minimum number of operations
    long long check(string s, long long cnt, int l, int r){
        
        // cout << s << " " << cnt << " " << l << " " << r << endl;
        int i = 0;
        char arr[s.length()];
        for(int i = 0; i<s.length(); i++){
            arr[i] = s[i];
        }
        int j = s.length()-1;
        while(i<j){
          if(arr[i] != arr[j]){
              if(j>r){
                  arr[j]= arr[i];
                  cnt++; 
              }
              else if(i < l ){
                  arr[i] = arr[j];
                  cnt++;
              }
             
          }
          i++;
          j--;
        }
        // for(int i = 0; i<s.length(); i++){
        //     cout << arr[i] << " ";
        // }
        // cout << endl;
         i = 0;
         j = s.length()-1;
        while(i<=j){
            if(arr[i] != arr[j])return INT_MAX;
            i++;
            j--;
        }
        return cnt;
    }
    public:
    int specialPalindrome(string s1, string s2){
        vector<pair<string, int>> v;
        int n = s1.size();
        vector<pair<int,int>> vp;
        for(int i = 0; i<=n-s2.size(); i++){
            int cnt = 0;
            string temp =  s1.substr(0,i);
            string temp2 = s1.substr(i,s2.length());
            int ind = i+s2.length();
            string temp3 = s1.substr(ind, n-ind+1);
            for(int j = 0; j<s2.length(); j++){
                if(s2[j] != temp2[j])cnt++;
            }
            v.push_back({temp+s2+temp3, cnt});
            vp.push_back({i,i+s2.length()-1});
           
        }
       
        long long mini = INT_MAX;
       
        for(int i = 0; i<=n-s2.size(); i++){
            
            long long c = check(v[i].first, v[i].second, vp[i].first, vp[i].second);
            mini = min(mini, c);
        
        }
        
        if(mini == INT_MAX)return -1;
        return mini;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        Solution obj;
        int ans = obj.specialPalindrome(s1,s2);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends