//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string S, string T) {
        int j = 0;
        int i = 0;
        for(; i<T.length();){
            if(T[i] >= 'A' and T[i] <= 'Z'){
                if(T[i] != S[j])return 0;
                i++;
                j++;
            }
            else{
                string temp = "";
                while(T[i] - '0' >=0 and T[i] - '0' <= 9){
                    temp += T[i++];
                }
                int k = stoi(temp);
                j += k;
                
            }
        }
        return (j == S.length());
        
        
       
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends