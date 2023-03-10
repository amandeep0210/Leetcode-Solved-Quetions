//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n)
    {
      sort(arr, arr+n);
      long long n1 = arr[n-1], n2 = arr[n-2], n3 = arr[n-3], n4 = arr[0], n5 = arr[1], n6 = arr[2];
      long long p1 = n1*n2*n3;
      long long p2 = n4*n5*n1;
      return max(p1, p2);
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends