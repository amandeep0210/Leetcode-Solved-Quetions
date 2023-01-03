//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int removeStudents(int H[], int N) {
        // it is a varient of LIS  using Binary Search:
        vector<int> v;
        v.push_back(H[0]);
        for(int i = 1; i<N; i++){
            if(v[v.size()-1] < H[i])v.push_back(H[i]);
            else{
                int rep = lower_bound(v.begin(), v.end(), H[i])-v.begin();
                v[rep] = H[i];
            }
        }
        return N-v.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends