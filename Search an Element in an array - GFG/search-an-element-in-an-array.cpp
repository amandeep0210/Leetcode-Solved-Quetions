//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to search x in arr
    // arr: input array
    // X: element to be searched for
    int ind;
    bool solve(int s, int e, int k, int v[]){
	if(s == e){
		if(v[s] == k){
		    ind = s;
		    return true;
		}
		return false;
	}
	int m = (s+e)/2;
	return solve(s, m, k, v) || solve(m+1, e, k, v);
}
    int search(int arr[], int N, int X)
    {
       if(solve(0,N-1,X,arr))return ind;
       return -1;
    }

};

//{ Driver Code Starts.

int main()
{
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        int sizeOfArray;
        cin>>sizeOfArray;
        int arr[sizeOfArray];
        int x;
        
        for(int i=0;i<sizeOfArray;i++)
        {
            cin>>arr[i];
        }
        cin>>x;
        Solution ob;
        cout<<ob.search(arr,sizeOfArray,x)<<endl; //Linear search
    }

    return 0;
    
}

// } Driver Code Ends