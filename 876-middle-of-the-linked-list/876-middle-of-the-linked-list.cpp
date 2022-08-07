class Solution {
public:
    ListNode* middleNode(ListNode* head){
        if(head == NULL or head->next == NULL){
            return head;
        }
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast != NULL){
            slow = slow->next;
            fast = fast->next;
            if(fast){
                fast = fast->next;
            }
        }
        return slow;
    }
};