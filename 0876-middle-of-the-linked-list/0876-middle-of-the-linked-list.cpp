/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int c = 0;
    int k = 0;
    ListNode* mid = NULL;
    void solve(ListNode* head){
        if(head == NULL){
            k = c;
            return ;
        }
        c++;
        solve(head->next);
        k--;
       if(k == c/2){
           mid = head;
       } 
     }
    
    ListNode* middleNode(ListNode* head) {
        solve(head);
        return mid;
    }
};