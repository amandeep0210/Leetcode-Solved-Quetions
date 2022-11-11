//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
     bool isPrime(int n){
         if(n == 1 or n == 0)return false;
         if(n == 2 or n == 3)
            return true;
         if(n%2 == 0 or n%3 ==0)
            return false;
         for(int i = 5; i*i <= n; i+= 6){
             if(n%i == 0 or n%(i+2) == 0)
                return false;
         }
         return true;
     }
    string isSumOfTwo(int N){
        bool f = false;
        for(int i = 2; i<=N; i++){
            if(isPrime(i)){
                if(isPrime(N-i)){
                    f = true;
                    break;
                }
            }
        }
        if(f)return "Yes";
        else return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isSumOfTwo(N) << endl;
    }
    return 0;
}

// } Driver Code Ends