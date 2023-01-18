//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int fn(int m, int tree[], int n){
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(tree[i] - m >= 0){
            cnt += (tree[i] - m);
            }
        }
        return cnt;
    }
    int find_height(int tree[], int n, int k)
    {
       sort(tree, tree+n);
       int l = -1;
       int r =  tree[n-1];
       while(r-l>1){
           int m = l + (r-l)/2;
               if(fn(m, tree, n) == k)return m;
               else if(fn(m, tree, n) < k){
                  r = m;
               }
               else{
                   l = m;
               }
       }
       return -1;
    }
    //6
    // 81 13 36 65 38 69
    // 47
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n;

        int tree[n];
        for(int i=0; i<n; i++)
            cin>>tree[i];
        cin>>k;
        Solution ob;
        cout<< ob.find_height(tree,n,k) << endl;
    }
    return 1;
}
// } Driver Code Ends