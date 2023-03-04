//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    long long bestNode(int n, vector<int> &A, vector<int> &P) {
        pair<int, int> parent[n+1];
        vector<int>childs[n+1];
        for(int i = 1; i<n; i++){
            childs[P[i]].push_back(i+1);
        }
        vector<int> leafs;
        for(int i = 1; i<=n; i++){
            if(childs[i].size() == 0)leafs.emplace_back(i);
        }
        for(int i = 0; i<n; i++){
            parent[i+1] = {A[i], P[i]};
        }
        long long maxi = INT_MIN;
        for(int i = 0; i < leafs.size(); i++){
            long long node = leafs[i];
            int pos = 1, neg = -1;
            pair<long long int, long long int> p = {0,0};
            while(node != -1){
                int val = parent[node].first;
                p.first += val*pos;
                p.second += val*neg;
                if(pos == 1){
                    maxi = max(maxi, p.first);
                }
                else if(neg == 1){
                    maxi = max(maxi, p.second);
                }
                pos *= -1;
                neg *= -1;
                node = parent[node].second;
            }
        }
        return maxi;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        long long res = obj.bestNode(N, A, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends