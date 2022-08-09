class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL or head->next == NULL){
            return head;
        }
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* fast = head->next;
        
        while(curr){
            curr->next = prev;
            prev = curr;
            curr = fast;
            if(fast){
              fast = fast->next;  
            } 
        }
        return prev;
    }
};