//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
       vector<int>l,r;
       stack<int> st1,st2;
       for(int i = 0; i<n; i++){
           if(st1.size() == 0){
               l.push_back(-1);
           }
           else{
               if(arr[st1.top()]<arr[i])l.push_back(st1.top());
               else{
                   while(st1.size() and arr[st1.top()]>= arr[i]){
                       st1.pop();
                   }
                   if(st1.size() == 0)l.push_back(-1);
                   else l.push_back(st1.top());
               }
           }
           st1.push(i);
       }
       
       for(int i = n-1;i>=0; i--){
            if(st2.size() == 0){
               r.push_back(-1);
           }
           else{
               if(arr[st2.top()]<arr[i])r.push_back(st2.top());
               else{
                   while(st2.size() and arr[st2.top()]>= arr[i]){
                       st2.pop();
                   }
                   if(st2.size() == 0)r.push_back(-1);
                   else r.push_back(st2.top());
               }
           }
           st2.push(i);
       }
       reverse(r.begin(), r.end());
 
       long long  a = 0;
       for(int i = 0; i<n; i++){
           if(r[i] == -1)r[i] = n;
           long long  length = r[i] - l[i] -1;
           long long  area = length * arr[i];
           a = max(a, area);
       }
       return a;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends