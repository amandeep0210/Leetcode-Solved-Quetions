//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
class Solution{
    public:
    int maximizeSum(int a[], int n) 
    {
        sort(a, a+n);
        unordered_map<int, int> mp;
        vector<int> v;
        for(int i = 0; i<n; i++){
            if(mp[a[i]] == 0){
                v.push_back(a[i]);
            }
            mp[a[i]]++;
        }
        // for(auto it : v) cout << it << " " ;
        // cout << endl;
        int sum = 0;
        for(int i = v.size()-1; i>=0; i--){
           if(mp[v[i]] == 0)continue;
           else{
               if(mp[v[i]-1]){
                   sum += (v[i] * mp[v[i]]);
                   mp[v[i]-1] -= min(mp[v[i]], mp[v[i]-1]);
               }
               else{
                   sum += (v[i]*mp[v[i]]);
                   
               }
           }
        }
        return sum;
    }

};


//{ Driver Code Starts.



int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        Solution ob;
        
        cout << ob.maximizeSum(arr, n) << endl;
        
        
    }

}


// } Driver Code Ends