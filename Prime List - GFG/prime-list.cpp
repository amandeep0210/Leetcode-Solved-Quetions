//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution{
public:
   void solve(vector<int>& primes, Node* &head){
       int n = primes.size();
       while(head){
          int l = lower_bound(primes.begin(), primes.end(), head->val)-primes.begin(); 
          int u = upper_bound(primes.begin(), primes.end(), head->val)-primes.begin();
          if(l == n)head->val = primes[n-1];
          else if(primes[l] == head->val)head->val = head->val;
          else if(head->val == 1)head->val = 2;
          else{
              
              int m1 = abs(head->val - primes[l-1]);
              int m2 = abs(head->val - primes[u]);
              if(m1<=m2)head->val = primes[l-1];
              else{
                  head->val = primes[u];
              }
          }
          head = head->next; 
       }
       return;
   }
    Node *primeList(Node *head){
        vector<bool> seive(1e5, true);
        seive[0] = false;
        seive[1] =  false;
        for(int i = 2; i*i < 1e5; i++){
            if(seive[i]){
                for(int j = i*i ; j< 1e5; j+= i){
                    seive[j] =  false;
                }
            }
        }
        vector<int>primes;
        for(int i = 0; i<1e5; i++){
            if(seive[i])primes.push_back(i);
        }
        Node* h1 = head;
        solve(primes, h1);
        return head;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends