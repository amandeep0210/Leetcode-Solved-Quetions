//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        vector<int> v(arr.begin(), arr.end());
        sort(v.begin(), v.end());
        long long sum = 0;
         vector<long long> pre;
         pre.push_back(v[0]);
         for(int i = 1; i<n; i++){
             pre.push_back(pre[i-1]+v[i]);
         }
         vector<long long> ans;
         for(int i = 0; i<n; i++){
             int l = lower_bound(v.begin(), v.end(), arr[i])-v.begin();
            //  cout << v[l] << endl;
             if(l == 0)ans.push_back(0);
             else ans.push_back(pre[l-1]);
         }
         return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends