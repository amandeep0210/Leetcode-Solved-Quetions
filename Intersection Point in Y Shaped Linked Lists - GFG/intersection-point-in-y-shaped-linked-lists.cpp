//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* inputList(int size)
{
    if (size == 0) return NULL;

    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}


// } Driver Code Ends
/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution
{
public:
    int cnt(Node* head){
        int c = 0;
        while(head){
            c++;
            head = head->next;
        }
        return c;
    }
    int intersectPoint(Node* h1, Node* h2)
    {
        // Your Code Here
       int ans = -1;
       int c1 = cnt(h1);
       int c2 = cnt(h2);
       int k = max(c1, c2);
       Node* p1, * p2;
       int inc = abs(c1-c2);
       if(k == c1)p1 = h1, p2 = h2;
       else {
           p1 = h2;
           p2 = h1;
       }
       while(inc--){
           p1 = p1->next;
       }
       while(true){
           if(p1 == p2)return p1->data;
           p1 = p1->next;
           p2= p2->next;
       }
       return -1;
       
       
    }
};



//{ Driver Code Starts.


/* Driver program to test above function*/
int main()
{
    int T, n1, n2, n3;

    cin >> T;
    while (T--)
    {
        cin >> n1 >> n2 >> n3;

        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);

        Node* temp = head1;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL) temp->next = common;

        temp = head2;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL) temp->next = common;
        
        Solution ob;
        cout << ob.intersectPoint(head1, head2) << endl;
    }
    return 0;
}


// } Driver Code Ends