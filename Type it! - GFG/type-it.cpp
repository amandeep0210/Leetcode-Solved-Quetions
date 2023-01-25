//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
         string t = "";
         int n = s.length();
         int c = 0;
        //  cout << s << endl;
        vector<int> v;
         for(int i = 0; i<n;){
            int len = t.length();
            string next = s.substr(i,len);
            string p = t;
            if(t.size() == 0){
                t += s[i++];
                c++;
            }
            else if(t == next){
                v.emplace_back(len);
                c++;
                t += next;
                 i += len;
            }
            else{
                c++;
                t += s[i++];
            }
        //   cout << p << " " <<next  << " " << "final : " << " " << t << " " <<c << endl;
         }
         if(v.size()){
        sort(v.begin(), v.end());
        for(int i = 0; i<v.size()-1; i++){
            c += v[i];
            c -= 1;
        }
        }
         return c;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends