//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestPerfectPiece(int arr[], int N) {
        if(N == 1)return 1;
        unordered_map<int, int>mp1,mp2;
        int ans = INT_MIN;
        int i = 0;
        int j = 0;
        while(j<N){
            mp1[arr[j]]++;
            if(mp1.size() == 1){
                ans = max(ans, j-i+1);
                j++;
            }
            if(mp1.size() > 1){
                while(mp1.size() > 1){
                    mp1[arr[i]]--;
                    if(mp1[arr[i]] == 0){
                        mp1.erase(arr[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        mp1.clear();
        i = 0;
        j = 0;
        while(j<N){
            mp1[arr[j]]++;
            if(mp1.size()<2){
                j++;
            }
            if(mp1.size()==2){
                vector<int>v1;
                for(auto it : mp1){
                    v1.push_back(it.first);
                }
                
                int a = v1[0];
                int b = v1[1];
                if(abs(a-b) == 1){
                   
                    ans = max(ans, j-i+1);
                }
                j++;
            }
            else if(mp1.size() > 2){
                while(mp1.size()>2){
                    mp1[arr[i]]--;
                    if(mp1[arr[i]] == 0){
                        mp1.erase(arr[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.longestPerfectPiece(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends