//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    bool isPossible(int m, int &n){
        int five = 0;
        while(m>=5){
            five += m/5;
            m = m/5;
        }
        return (five >= n);
    }
        int findNum(int n)
        {
        int l = 4;
        int r = 1e8;
        while(r-l>1){
            int m  = l + (r-l)/2;
            if(isPossible(m,n)){
                r = m;
            }
            else{
                l = m;
            }
        }
        return r;
        }
};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}
// } Driver Code Ends