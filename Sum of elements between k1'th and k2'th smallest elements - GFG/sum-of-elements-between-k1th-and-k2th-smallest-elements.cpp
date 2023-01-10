//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        priority_queue<long long int> maxHeap;
        int n = K2-K1-1;
        for(int i = 0; i<N; i++){
            maxHeap.push(A[i]);
            if(maxHeap.size() > K2)maxHeap.pop();
        }
        maxHeap.pop();
        long long sum = 0;
        while(n-- and maxHeap.size()){
            sum += maxHeap.top();
            maxHeap.pop();
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}

// } Driver Code Ends