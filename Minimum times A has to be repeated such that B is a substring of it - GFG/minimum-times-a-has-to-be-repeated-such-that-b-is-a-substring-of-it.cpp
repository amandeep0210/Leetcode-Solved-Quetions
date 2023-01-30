//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string A, string B) {
        string temp = A;
        int cnt = 1;
        while(temp.length() < B.length()){
            temp += A;
            cnt++;
        }
        if(temp.find(B) == -1){
            temp += A;
            if(temp.find(B) != -1)return cnt+1;
            return -1;
        }
        else return cnt;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends