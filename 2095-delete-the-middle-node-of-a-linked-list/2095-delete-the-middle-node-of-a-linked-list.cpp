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
    ListNode* deleteMiddle(ListNode* head) {
       
        if(head-> next == NULL) { 
            head = NULL;
            return head;
        } 
        ListNode * h1 = head , * h2 = head , * h3 = h2;
        while(h1-> next and h1->next->next){
            h3  = h2 ;
            h2 = h2-> next;
            h1 = h1->next->next;
            }
        if(h1->next){
            ListNode* k =h2-> next;
            h2-> next  = k-> next;
            k = NULL;
            return head;
            }
        h3-> next = h2-> next;
        h2 = NULL;
        return head;
    }
};