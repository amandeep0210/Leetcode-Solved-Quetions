//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
long long numOfWays(int N, int M)
{   long long int mod = 1000000007;
    long long  cnt = 0;
    long long  total = N*M;
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=M; j++){
            int c = 0;
            if(i-2 >= 1 and j-1 >=1)c++;
            if(i-2 >=1 and j+1 <= M)c++;
            if(i-1>=1 and  j-2 >=1)c++;
            if(i-1>=1 and j+2 <=M )c++;
            if(i+1<=N and j-2 >=1)c++;
            if(i+1<=N and j+2 <=M)c++;
            if(i+2<=N and j-1 >=1 )c++;
            if(i+2<= N and j+1 <=M)c++;
            cnt += (total - c -1)%mod;
            
        }
    }
    return cnt%mod;
}