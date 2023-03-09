//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList() {
    int n; // length of link list
    scanf("%d ", &n);

    char data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i) {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
  public:
  bool isValid(int mp1[], int mp2[]){
      for(int i = 0; i<26; i++){
          if(mp1[i] != mp2[i])return false;
      }
      return true;
  }
    vector<Node*> findAnagrams(struct Node* head, string s) {
        vector<Node*> result;
       Node * head1 = head, *head2 = head;
       int i = 0, j = 0;
       int mp1[26] = {0};
       for(auto it : s){
           mp1[it-'a']++;
       }
       int k = s.size();
       int mp2[26] = {0};
       while(head2){
           mp2[head2->data - 'a']++;
           if(j-i+1 < k){
               j++;
               head2 = head2->next;
           }
           else{
               if(j-i+1 == k){
                   if(isValid(mp1, mp2)){
                       Node* temp = head2->next;
                       head2->next = NULL;
                       result.push_back(head1);
                       head2 = temp;
                       j++;
                       i = j;
                       head1 = head2;
                       for(int i = 0; i< 26; i++){
                           mp2[i] = 0;
                       }
                       
                   }
                   else{
                      mp2[head1->data - 'a']--;
                      i++;
                      j++;
                      head2 = head2->next;
                      head1 = head1->next;
                   }
               }
           }
       }
    //   cout << result.size() << endl;
       return result;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        struct Node *head = inputList();

        string s;
        cin >> s;

        Solution obj;
        vector<Node *> res = obj.findAnagrams(head, s);

        for (int i = 0; i < res.size(); i++) {
            printList(res[i]);
        }

        if (res.size() == 0) cout << "-1\n";
    }
}

// } Driver Code Ends