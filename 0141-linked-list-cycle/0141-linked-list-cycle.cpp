/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
       
        ListNode *dummy = new ListNode(0);
        
        
        ListNode* curr = head;
        bool flag = true; 
        while (curr != nullptr && flag) {
            ListNode *temp = curr; 
            
            if (temp -> next == dummy) {
                return true;
            }
            curr = curr -> next; 
            temp -> next = dummy ;
            
        }
       
         return false; 
            
    }
};