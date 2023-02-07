//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &arr,int n){
           //code here
           int i = 0;
           int j = 0;
           int s = -1;
           int e = -1;
           int cnt = 0;
           int ans = 0;
           while(j<n){
               if(arr[j] > 0)j++;
               else if(arr[j] < 0){
                   cnt++;
                   if(s == -1)s = j;
                   e = j;
                   j++;
                //   cout <<s << " " << e << endl;
               }
               else if(arr[j] == 0){
                   int len = j-i;
                //   cout << len << endl;
                   if(cnt%2 == 0)ans = max(ans, len);
                   else{
                       int l1 = s-i+1;
                       int l2 = j-e;
                       ans = max(ans,max(len-l1, len-l2));
                   }
                   j++;
                   i = j;
                   cnt = 0;
                   s = -1;
                   e = -1;
               }
           }
        //   cout << ans << endl;
           if(j-i > 0){
               int len = j-i;
               if(cnt%2 == 0)ans =  max(ans, len);
               else{
               
                    int l1 = s-i+1;
                       int l2 = j-e;
                       ans = max(ans , max(len-l1, len-l2));
               }
           }
           return ans;
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends