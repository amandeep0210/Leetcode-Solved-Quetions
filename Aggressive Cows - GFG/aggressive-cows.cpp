//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool isPossible(int &dis, int &k,  vector<int> &stalls){
        int i = 0;
        int c = 0;
        int prev = 0;
        int n = stalls.size();
        while(i<stalls.size()){
            if(c == k and i<= n-1){
                return true;
            }
            if(c == 0){
                c++;
                prev = stalls[0];
                i++;
                
            }
            else{
                if(stalls[i] - prev < dis){
                    i++;
                }
                else{
                    prev = stalls[i++];
                    c++;
                }
            }
        }
        if(c == k)return true;
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(), stalls.end());
        int s = 1;
        int e = stalls[n-1] - stalls[0];
        int ans = 1;
        while(s<=e){
            int m = s + (e-s)/2;
            if(isPossible(m, k, stalls)){
                ans = m;
                s = m+1;
            }
            else{
                e = m -1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends