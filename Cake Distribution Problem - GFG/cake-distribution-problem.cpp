//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    int isPossible(int mid, vector<int>& v, int k){
        long long sum = 0;
        int cnt = 0;
        for(int i = 0; i < v.size(); i++){
            sum += v[i];
            if(sum >= mid){
                cnt++;
                sum = 0;
            }
        }
        return cnt;
        
    }
    int maxSweetness(vector<int>& sweetness, int N, int K) {
     long long sum = 0;
     for(auto it : sweetness)sum += it;
     int s = -1;
     int e = sum+1;
     int ans = 0;
     while(e-s> 1){
         int mid = s + (e-s)/2;
         if(isPossible(mid, sweetness,K) < K+1)e = mid;
         else s = mid;
     }
     return s;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends