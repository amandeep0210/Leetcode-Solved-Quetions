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
      long long num1 =INT_MIN , num2 = INT_MIN, num3 = INT_MIN;
      int ind1, ind2, ind3;
      for(int i = 0; i< n ; i++){
          if(arr[i] > num1){
              num1 = arr[i];
              ind1 = i;
          }
      }
      for(int i = 0; i<n; i++){
          if(i == ind1)continue;
          if(arr[i] > num2){
              num2 = arr[i];
              ind2 = i;
          }
      }
      for(int i = 0; i<n; i++){
          if(i == ind1  || i == ind2)continue;
          if(arr[i] > num3){
              num3 = arr[i];
          }
      }
      
      long long num4 = INT_MAX, num5 = INT_MAX;
      for(int i = 0; i<n; i++){
          if(arr[i] < num4){
              num4 = arr[i];
              ind1 = i;
          }
      }
      for(int  i = 0; i<n; i++){
          if(i == ind1)continue;
          if(arr[i] < num5){
              num5 = arr[i];
          }
      }
      
      return max(num1*num2*num3, num1*num4*num5);
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