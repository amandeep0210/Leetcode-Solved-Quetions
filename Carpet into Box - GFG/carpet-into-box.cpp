//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int carpetBox(int A, int B, int C, int D){
       int cnt1 = 0;
       int cnt2 = 0;
       int l = A;
       int b = B;
       while(l > C || b > D){
           if(l>C){
               cnt1++;
               l /= 2;
           }
           if(b > D){
               cnt1 ++ ;
               b /= 2;
           }
       }
       // now consider the A as breath and B as lenth ;
       l = B;
       b = A;
       while(l > C || b > D){
           if(l>C){
               cnt2++;
               l /= 2;
           }
           if(b > D){
               cnt2 ++ ;
               b /= 2;
           }
       }
       return min(cnt1,cnt2);
    }
    //131203071 738050652 84 5
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends