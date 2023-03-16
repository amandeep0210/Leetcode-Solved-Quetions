//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

long long int no_of_subarrays(int n, vector<int> &arr) {
    long long int cnt = 0;
    long long int c = 0 ;
    for(int i = 0; i<n; i++){
        if(arr[i] == 0){
            c++;
        }
        else{
            cnt += (c*1LL*(c+1)/2);
            c = 0;
        }
    }
    cnt += (c*(c+1)/2);
    return cnt;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << no_of_subarrays(n, arr) << endl;
    }
}

// } Driver Code Ends